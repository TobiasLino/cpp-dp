#include <iostream>
#include <memory>

#include "abstractFactory.h"
#include "abstractProduct.h"

#include "../../tests.h"

namespace abstractFactoryTests {

	void test1() {
		ConcreteFactoryA* factory = new ConcreteFactoryA();
		const auto productA = factory->makeProductA();
		const auto productB = factory->makeProductB();
		delete factory;

		equals_string(productA->toString(), "Name: caixa1, type: box, size: 10.2", "teste1");
		equals_string(productB->toString(), "Name: pc1, type: computer", "teste2");
	}


	void test2() {
		ConcreteFactoryB* factory = new ConcreteFactoryB();
		const auto productA = factory->makeProductA();
		const auto productB = factory->makeProductB();
		delete factory;

		equals_string(productA->toString(), "Name: caixa2, type: box2, size: 20.2", "teste3");
		equals_string(productB->toString(), "Name: pc2, type: computer2", "teste4");
	}

}

int main() {
	abstractFactoryTests::test1();
	abstractFactoryTests::test2();

	return EXIT_SUCCESS;
}
