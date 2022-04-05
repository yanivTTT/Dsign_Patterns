//
// Created by lkyni on 3/31/2022.
//

#include <iostream>
using namespace std;
class Animal{
public:
    virtual void sound() = 0;
};

class Dog: public Animal{
public:
    void sound() override {
        cout << "Bark Bark" <<endl;
    };
};

class Cat : public Animal{
public:
    void sound() override {
        cout << "Meow Meow" <<endl;
    };
};
class Target{
public:
    virtual void request() = 0;
};

class Adapter: public Target {
private:
    Animal* _an;
public:
    Adapter(Animal* an) {
        _an = an;
    }
    void request() override {
        _an->sound();
    }
};

/*int main() {
    Target* target = new Adapter(new Cat());
    Target* target2 = new Adapter(new Dog());
    target->request();
    target2->request();
}*/
