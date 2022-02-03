#include <memory>

#include "builder.h"
#include "../../tests.h"

void test1() {
	std::unique_ptr<EmployeeBuilder> builder = std::unique_ptr<EmployeeBuilder>(new EmployeeBuilder());
	builder->name("tobias");
	builder->employeeType("simples");
	builder->CPF("123456789");
	builder->age(10);
	std::unique_ptr<Employee> emp = std::unique_ptr<Employee>(builder->build());

	equals_string(emp->toString(), "Name: tobias, employeeType: simples, CPF: 123456789, age: 10", "teste1");
}

int main() {
	test1();

	return EXIT_SUCCESS;
}
