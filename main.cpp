class Point {
private:
    int _x;
    int _y;
public:
    Point(const Point* p) {
        _x = p->_x;
    }
};