#pragma once
#ifndef CREATIONAL_ABSTRACT_FACTORY
#define CREATIONAL_ABSTRACT_FACTORY

#include <memory>

#include "abstractProduct.h"

class AbstractFactory {
protected:

	AbstractFactory() {}

public:
	virtual std::unique_ptr<AbstractProductA> makeProductA() const = 0;
	virtual std::unique_ptr<AbstractProductB> makeProductB() const = 0;
};

class ConcreteFactoryA : public AbstractFactory {
public:
	ConcreteFactoryA() : AbstractFactory() {}

	std::unique_ptr<AbstractProductA> makeProductA() const override {
		return std::unique_ptr<AbstractProductA>(new Box("caixa1", 10.2F));
	}
	std::unique_ptr<AbstractProductB> makeProductB() const override {
		return std::unique_ptr<AbstractProductB>(new Computer("pc1"));
	}
};

class ConcreteFactoryB : public AbstractFactory {
public:
	ConcreteFactoryB() : AbstractFactory() {}

	std::unique_ptr<AbstractProductA> makeProductA() const override {
		return std::unique_ptr<AbstractProductA>(new Box2("caixa2", 20.2F));
	}
	std::unique_ptr<AbstractProductB> makeProductB() const override {
		return std::unique_ptr<AbstractProductB>(new Computer2("pc2"));
	}
};

#endif // CREATIONAL_ABSTRACT_FACTORY
