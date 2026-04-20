#ifndef CS_POINT_HPP
#define CS_POINT_HPP

#include <iostream>

class Point{
public:
    Point();
    Point(double, double);

    void   init (double, double);
    double getx () { return x; };
    double gety () { return y; };
    void   setx (double);
    void   sety (double);
    Point  add  (const Point&);
    Point  sub  (const Point&);
    void   print(std::ostream&); 
private:
    double x, y;
};

#endif