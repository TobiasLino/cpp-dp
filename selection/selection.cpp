#include <map>
#include <string>
#include <iostream>

class ActionExecutor {
public:
	virtual void execute() const = 0;
};

class ArrowUp : public ActionExecutor {
public:
	void execute() const override {
		std::cout << "ArrowUp" << std::endl;
	}
};
class ArrowDown : public ActionExecutor {
public:
	void execute() const override {
		std::cout << "ArrowDown" << std::endl;
	}
};
class ArrowLeft : public ActionExecutor {
public:
	void execute() const override {
		std::cout << "ArrowLeft" << std::endl;
	}
};
class ArrowRight : public ActionExecutor {
public:
	void execute() const override {
		std::cout << "ArrowRight" << std::endl;
	}
};


class Executor {
public:
	Executor(std::map<std::string, ActionExecutor*> actions) : actions_(actions) {
	}

	ActionExecutor* get(std::string action) {
		return actions_.lower_bound(action)->second;
	}

private:
	std::map<std::string, ActionExecutor*> actions_;
};

int main() {
	auto up = new ArrowUp();
	auto down = new ArrowDown();
	auto left = new ArrowLeft();
	auto right = new ArrowRight();

	std::map<std::string, ActionExecutor*> actions;
	actions.insert(std::pair<std::string, ActionExecutor*>("UP", up));
	actions.insert(std::pair<std::string, ActionExecutor*>("DOWN", down));
	actions.insert(std::pair<std::string, ActionExecutor*>("LEFT", left));
	actions.insert(std::pair<std::string, ActionExecutor*>("RIGHT", right));

	Executor* executor = new Executor(actions);

	std::string option;
	std::cout << ": ";
	std::cin >> option;
	while (option.compare("EXIT") != 0) {
		if (option.empty()) {
			continue;
		}
		executor->get(option)->execute();

		std::cout << ": ";
		std::cin >> option;
	}

	delete up;
	delete down;
	delete left;
	delete right;
	delete executor;

	return EXIT_SUCCESS;
}
