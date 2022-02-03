#pragma once
#ifndef CREATIONAL_BUILDER
#define CREATIONAL_BUILDER

#include <string>

class Employee {
public:
	Employee() { this->age_ = 0; }

	std::string getName();
	std::string getEmployeeType();
	std::string getCPF();
	int getAge();

	void setName(std::string name);
	void setEmployeeType(std::string type);
	void setCPF(std::string CPF);
	void setAge(int age);

	std::string toString();

private:
	std::string name_;
	std::string employeeType_;
	std::string CPF_;
	int age_;
};

class EmployeeBuilder {
public:
	EmployeeBuilder();

	void name(std::string name);
	void employeeType(std::string type);
	void CPF(std::string CPF);
	void age(int age);

	Employee* build();

private:
	Employee* employee_;
};

#endif // CREATIONAL_BUILDER
