#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

point::point() : x(0), y(0) {}

point::point(float x, float y) : x(x), y(y) {}

void point::setX(float x) {
    this->x = x;
}

void point::setY(float y) {
    this->y = y;
}

float point::getX() const {
    return x;
}

float point::getY() const {
    return y;
}

void point::display() const {
    cout << "(" << x << ", " << y << ")";
}

float point::distance(const point& p) const {
    return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}
