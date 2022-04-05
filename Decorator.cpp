//
// Created by lkyni on 3/30/2022.
//
#include <iostream>
#include <cstring>

using namespace std;

class Pizza {
public:
    virtual int getPrice() = 0;
    virtual string getDescription()=0;
};

class familyPizza : public Pizza {
    int getPrice() override {
        return 50;
    }
    string getDescription() override {
        return "family pizza";
    }
};
class privatPizza : public Pizza {
    int getPrice() override {
        return 30;
    }
    string getDescription() override {
        return "privat pizza";
    }
};

class PizzaDecortor: public Pizza {
protected:
    Pizza* _pizza;
public:
    virtual int getPrice()=0;
    virtual string getDescription()=0;
};
class onionPizza: public PizzaDecortor {
public:
    onionPizza(Pizza* pizza1) {
        _pizza = pizza1;
    }
    int getPrice() override {
        return _pizza->getPrice() + 4;
    }
    string getDescription() override {
        return _pizza->getDescription() + " with onions";
    }
};

class olivePizza: public PizzaDecortor {
public:
    olivePizza(Pizza* pizza1) {
        _pizza = pizza1;
    }
    int getPrice() override {
        return _pizza->getPrice() + 3;
    }
    string getDescription() override {
        return _pizza->getDescription() + " with olives";
    }
};
/*
int main() {
    Pizza* pizza = new olivePizza(new familyPizza());
    Pizza* pizza2 = new olivePizza(new onionPizza(new privatPizza()));
    cout <<"pizza1: "<< pizza->getDescription()<<endl;
    cout <<"pizza1 price: "<< pizza->getPrice()<<endl;
    cout <<"pizza2: "<< pizza2->getDescription()<<endl;
    cout <<"pizza2 price: "<< pizza2->getPrice()<<endl;
    return 0;
}*/
