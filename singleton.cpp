//
// Created by lkyni on 3/31/2022.
//
#include <iostream>
#include <cstring>
using namespace std;

class Robot {
private:
    friend class Singleton;
    char  *_name;
    Robot(){
        strcpy(_name, "myRobot");
    }
};
class Singleton{
private:
    Robot* robot;
public:
    Robot* getRobot() {
        if (!robot) {
            return new Robot();
        }
    }
};
int main() {
    Singleton singleton;
    Robot* r1 = singleton.getRobot();
    cout << "r1 address=" << r1 << endl;
    Robot* r2 = singleton.getRobot();
    cout << "r2 address=" << r2 << endl;
}