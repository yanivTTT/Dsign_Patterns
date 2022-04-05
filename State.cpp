//
// Created by lkyni on 3/30/2022.
//
#include <iostream>
#include <cstring>

using namespace std;

class State {
public:
    virtual void sleep() = 0;
};
class Sleepy: public State {
    void sleep() override {
        cout << "i am felling sleepy"<< endl;
    }
};

class Awake: public State {
    void sleep() override {
        cout << "i dont want to sleep"<< endl;
    }
};

class Kid {
private:
    State* _sleep;
public:
    Kid(State* s) {
        _sleep = s;
    }
    void goToSleep() {
        _sleep->sleep();
    }
    void setSleep(State* s) {
        _sleep = s;
    }
};
/*
int main() {
    Sleepy* spy = new Sleepy();
    Awake* awk = new Awake();
    Kid* myKid = new Kid(spy);
    myKid->goToSleep();
    myKid->setSleep(awk);
    myKid->goToSleep();
}*/
