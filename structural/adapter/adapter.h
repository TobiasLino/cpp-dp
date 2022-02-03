#pragma once
#ifndef STRUCTURAL_ADAPTER
#define STRUCTURAL_ADAPTER

#include <string>
#include <sstream>

class Type1 {
public:
	Type1(int x, int y) : x_(x), y_(y) {}

	std::string toString() {
		std::stringstream stream;
		stream << "x: " << x_ << ", y: " << y_;
		return stream.str();
	}

private:
	int x_;
	int y_;
};

class Type2 {
public:
	Type2(std::string a, std::string b) : a_(a), b_(b) {}

	std::string toString() {
		std::stringstream stream;
		stream << "a: " << a_ << ", b: " << b_;
		return stream.str();
	}

private:
	std::string a_;
	std::string b_;
};

class Type3 {
private:
	int x_;
	int y_;
	std::string a_;
	std::string b_;
};

#endif // STRUCTURAL_ADAPTER