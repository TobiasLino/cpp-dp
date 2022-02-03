#include <iostream>
#include <memory>

class Delivery {
public:
    virtual void deliverPackage() const = 0;
    virtual double getDeliverPrice() const = 0;
};

class Sedex : public Delivery {
public:
    Sedex() {}

    void deliverPackage() const override {
        std::cout << "Entregando por Sedex, valor do frete: " << getDeliverPrice() << std::endl;
    }

    double getDeliverPrice() const override {
        return 42.5F;
    }
};

class Correios : public Delivery {
public:
    Correios() {}

    void deliverPackage() const override {
        std::cout << "Entregando por Correios, valor do frete: " << getDeliverPrice() << std::endl;
    }

    double getDeliverPrice() const override {
        return 22.5F;
    }
};

class DeliveryService {
public:
    DeliveryService(Delivery* delivery = nullptr) : delivery_(delivery) {}

    void deliver() {
        this->delivery_->deliverPackage();
    }

    ~DeliveryService() {
        delete delivery_;
    }
private:
    Delivery* delivery_;
};

/*
 * TESTS
 */
// unique_ptr<T>(new T) cria um smar pointer passando o objeto
void mustPrintTheSedexService() {
    auto service = std::unique_ptr<DeliveryService>(new DeliveryService(new Sedex()));
    service->deliver();
}

// make_unique cria smart pointers passando os parâmetros do construtor do objeto
void mustPrintTheCorreiosService() {
    auto service = std::make_unique<DeliveryService>(new Correios());
    service->deliver();
}

int main() {
    mustPrintTheSedexService();
    mustPrintTheCorreiosService();

    return EXIT_SUCCESS;
}
