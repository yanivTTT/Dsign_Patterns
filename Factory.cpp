#include <iostream>
#include <map>
#include <functional>

using namespace std;
class Shape {
protected:
    string _shape;
public:
    void paint() {
        cout << _shape << " painted" << endl;
    }
};
// our first shape
class Circle: public Shape{
public:
    Circle() {
        _shape = "circle";
    }
};
// our second shape
class Rectangle: public Shape{
public:
    Rectangle() {
        _shape = "Rectangle";
    }
};
//the shape factory we want to create
class ShapeFactory {
    map<string, std::function<Shape*()>> _map;
public:
    ShapeFactory() {
        _map.insert({"Circle", []() {return (Shape*) new Circle(); }});
        _map.insert({"Rectangle", []() {return (Shape*) new Rectangle(); }});
    }
    //the wat we want to create different object of the same type
    Shape *create(const string& key) {
        if (_map.find(key) != _map.end()) {
            return _map.at(key)();
        }
        return nullptr;
    }
};
/*int main() {
    ShapeFactory* shapeFactory = new ShapeFactory();
    Shape *circle1 = shapeFactory->create("Circle");
    Shape *circle2 = shapeFactory->create("Circle");
    circle1->paint();
    circle2->paint();
    std::cout << &circle1 << std::endl;
    std::cout << &circle2 << std::endl;
    return 0;
}*/
