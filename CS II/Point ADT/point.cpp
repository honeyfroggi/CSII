#include "point.hpp"
#include <iostream>

Point::Point(){
    x = 0; 
    y = 0;
}

Point::Point(double newx, double newy){ //with constructor
    x = newx;
    y = newy;
}

void Point::init(double newx, double newy){ //without constructor
    x = newx;
    y = newy;
}

void Point::setx(double newx){
    x = newx;
}

void Point::sety(double newy){
    y = newy;
}

Point Point::add(const Point& rhs){
    Point result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    return result;
}

Point Point::sub(const Point& rhs){
    Point result;
    result.x = x - rhs.x;
    result.y = y - rhs.y;
    return result;
}

void Point::print(std::ostream& out){
    out << "(" << x << ", " << y << ")" << std::endl;
}