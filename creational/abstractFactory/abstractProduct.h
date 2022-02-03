#pragma once
#ifndef CREATIONAL_ABSTRACT_PRODUCT
#define CREATIONAL_ABSTRACT_PRODUCT

#include <string>
#include <sstream>

class AbstractProductA {
public:
	virtual std::string toString() const = 0;

protected:

	AbstractProductA(std::string name, std::string type, double size) : name_(name), type_(type), size_(size) {}

	std::string name_;
	std::string type_;
	double size_;
};

class Box : public AbstractProductA {
public:
	Box(std::string name, double size) : AbstractProductA(name, "box", size) {}

	std::string toString() const override {
		std::stringstream stream;
		stream << "Name: " << this->name_ << ", type: " << this->type_ << ", size: " << this->size_;
		return stream.str();
	}
};

class Box2 : public AbstractProductA {
public:
	Box2(std::string name, double size) : AbstractProductA(name, "box2", size) {}

	std::string toString() const override {
		std::stringstream stream;
		stream << "Name: " << this->name_ << ", type: " << this->type_ << ", size: " << this->size_;
		return stream.str();
	}
};


class AbstractProductB {
public:
	virtual std::string toString() const = 0;

protected:

	AbstractProductB(std::string name, std::string type) : name_(name), type_(type) {}

	std::string name_;
	std::string type_;
};

class Computer : public AbstractProductB {
public:
	Computer(std::string name) : AbstractProductB(name, "computer") {}

	std::string toString() const override {
		std::ostringstream stream;
		stream << "Name: " << this->name_ << ", type: " << this->type_;
		return stream.str();
	}
};


class Computer2 : public AbstractProductB {
public:
	Computer2(std::string name) : AbstractProductB(name, "computer2") {}

	std::string toString() const override {
		std::stringstream stream;
		stream << "Name: " << this->name_ << ", type: " << this->type_;
		return stream.str();
	}
};

#endif // CREATIONAL_ABSTRACT_PRODUCT
