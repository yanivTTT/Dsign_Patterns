//
// Created by lkyni on 3/31/2022.
//
#include <iostream>
#include <cstring>

using namespace std;

class dog{
public:
    void sound() {
        cout << "bark brak";
    }
};
class Target{
public:
    virtual void request() = 0;
};

class Adapter: public Target, public dog {
    void request() override {
        sound();
    }
};

/*
int main() {
    Target* target = new Adapter();
    target->request();
}*/
