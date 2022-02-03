#include <sstream>

#include "builder.h"

std::string Employee::getName() {
	return this->name_;
}

std::string Employee::getEmployeeType() {
	return this->employeeType_;
}

std::string Employee::getCPF() {
	return this->CPF_;
}

int Employee::getAge() {
	return this->age_;
}

void Employee::setName(std::string name) {
	this->name_ = name;
}

void Employee::setEmployeeType(std::string type) {
	this->employeeType_ = type;
}

void Employee::setCPF(std::string CPF) {
	this->CPF_ = CPF;
}

void Employee::setAge(int age) {
	this->age_ = age;
}

std::string Employee::toString() {
	std::stringstream stream;
	stream << "Name: " << getName() << ", employeeType: " << getEmployeeType() << ", CPF: " << getCPF() << ", age: " << getAge();
	return stream.str();
}

EmployeeBuilder::EmployeeBuilder() {
	this->employee_ = new Employee();
}

void EmployeeBuilder::name(std::string name) {
	employee_->setName(name);
}

void EmployeeBuilder::employeeType(std::string type) {
	employee_->setEmployeeType(type);
}

void EmployeeBuilder::CPF(std::string CPF) {
	employee_->setCPF(CPF);
}

void EmployeeBuilder::age(int age) {
	employee_->setAge(age);
}

Employee* EmployeeBuilder::build() {
	return this->employee_;
}
