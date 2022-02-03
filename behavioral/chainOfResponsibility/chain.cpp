#include <iostream>
#include <memory>
#include <string>

class Authentication {
public:
	Authentication(std::string user, bool isAuthenticated) 
		: user_(user), isAuthenticated_(isAuthenticated) {}

	bool isAuthenticated() {
		return this->isAuthenticated_;
	}

	std::string getUser() {
		return this->user_;
	}

private:
	std::string user_;
	bool isAuthenticated_;
};

struct AuthenticationEvent {
	std::string user;
	std::string passwd;
};

struct AuthenticationContext {
	std::string type;
	Authentication* auth;
	std::string cookie;
};

class Filter {
public:
	Filter() : nextFilter_(nullptr) {}

	Filter* setNext(Filter* filter) {
		this->nextFilter_ = filter;
		return this->nextFilter_;
	}

	virtual Authentication* doFilter(
		AuthenticationEvent event,
		AuthenticationContext context) const = 0;

protected:
	Authentication* nextFilter(AuthenticationEvent event, AuthenticationContext context) const {
		if (this->nextFilter_) {
			return this->nextFilter_->doFilter(event, context);
		}
		else {
			return context.auth;
		}
	}

	Filter* nextFilter_;
};

class ChangeAutenticationType : public Filter {
public:
	ChangeAutenticationType() : Filter() {}

	Authentication* doFilter(AuthenticationEvent event, AuthenticationContext context) const override {
		context.type = "BasicAuth";
		std::cout << "The type of Authentication is: " << context.type << std::endl;
		
		return nextFilter(event, context);
	}
};

class AuthenticateUser : public Filter {
public:
	AuthenticateUser() : Filter() {}

	Authentication* doFilter(AuthenticationEvent event, AuthenticationContext context) const override {
		std::cout << "Authenticating user \"" << event.user << "\" ..." << std::endl;
		if (event.passwd == "123456789") {
			context.auth = new Authentication(event.user, true);
		} else {
			context.auth = new Authentication(event.user, false);
		}

		return nextFilter(event, context);
	}
};

class DefineAuthenticationCookie : public Filter {
public:
	DefineAuthenticationCookie() : Filter() {}

	Authentication* doFilter(AuthenticationEvent event, AuthenticationContext context) const override {
		if (context.auth->isAuthenticated()) {
			std::cout << "Setting Authentication cookie as Authorization: Bearer" << std::endl;
			context.cookie = "Authorization: Bearer";
		}

		return nextFilter(event, context);
	}
};

class AuthenticationService {
public:
	AuthenticationService(Filter* filter) : firstFilter_(filter) {}

	Authentication* authenticate(std::string user, std::string passwd) {
		AuthenticationEvent event;
		event.user = user;
		event.passwd = passwd;

		AuthenticationContext context;
		context.auth = nullptr;
		context.cookie = "";
		context.type = "";

		return this->firstFilter_->doFilter(event, context);
	}

private:
	Filter* firstFilter_;
};

int main() {
	auto firstFilter = new ChangeAutenticationType();
	auto secondFilter = new AuthenticateUser();
	auto thirdFilter = new DefineAuthenticationCookie();

	std::string user;
	std::string passwd;

	std::cout << "usuario: ";
	std::cin >> user;
	std::cout << "passwd: ";
	std::cin >> passwd;

	firstFilter->setNext(secondFilter)->setNext(thirdFilter);

	auto service = std::make_unique<AuthenticationService>(firstFilter);

	auto auth = std::unique_ptr<Authentication>(service->authenticate(user, passwd));

	std::cout << "User \"" << auth->getUser() << "\" "
		<< (auth->isAuthenticated() ? "AUTHENTICATED" : "NOT AUTHENTICATED")
		<< std::endl;

	delete firstFilter;
	delete secondFilter;
	delete thirdFilter;

	return EXIT_SUCCESS;
}
