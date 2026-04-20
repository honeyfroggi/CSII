// CS 23001 Spring 2026
// Data Structures and Abstraction
// Lesson on Abstraction, Inheritance and Virtual Methods
// April 8th
// Dr. Maletic
// Max Bird

#include <iostream>

// Abstract Class
class shape{
public:
    shape() : x(0), y(0) {};
    virtual ~shape() {};
    void move(int nx, int ny) {x = nx; y = ny; } ;
    // virtual method 
    virtual void draw() const = 0;
    virtual bool isSquare() const = 0;
    virtual bool isRectangle() const = 0;
    virtual bool isCircle() const = 0;
    virtual bool isTriangle() const = 0;

protected:
    int x, y;
};


class rectangle : public shape{
public:
    rectangle() : shape(), h(0), w(0) {};
    rectangle(int nh, int nw) : shape(), h(nh), w(nw) {};
    // virtual method
    virtual void draw() const { std::cout << "rectangle (" << h << ", " << w  << ") at " 
                        << x << ", " << y << std::endl; };
    virtual bool isSquare() const { return false; };
    virtual bool isRectangle() const { return true; };
    virtual bool isCircle() const {return false; };
    virtual bool isTriangle() const { return false; };

protected:
    int h, w;
};


class square : public rectangle{
public: 
    square() : rectangle() {};
    square(int nh) : rectangle(nh, nh) {};
    virtual void draw() const { std::cout << "square (" << h << ", " << w  << ") at " 
                        << x << ", " << y << std::endl; };
    virtual bool isSquare() const { return true; };
    virtual bool isRectangle() const { return true; };
    virtual bool isCircle() const {return false; };
    virtual bool isTriangle() const { return false; };
};


class triangle : public shape{
public:
    triangle() : shape(), base(0), height(0) {};
    triangle(int nh, int nb) : shape(), base(nb), height(nh) {}; 
    virtual void draw() const { std::cout << "Triangle (" << base << ", " << height << ") at "
                                << x << ", " << y << std::endl; };
    virtual bool isSquare() const { return false; };
    virtual bool isRectangle() const { return false; };
    virtual bool isCircle() const {return false; };
    virtual bool isTriangle() const { return true; };

private:
    int base, height;
};



class circle : public shape{
public:
    circle() : shape(), radius(0) {};
    circle(int nr) : shape(), radius(nr) {};
    virtual void draw() const { std::cout << "Circle with radius " << radius << " at " 
                        << x << ", " << y << std::endl; };
        virtual bool isSquare() const { return false; };
    virtual bool isRectangle() const { return false; };
    virtual bool isCircle() const {return true; };
    virtual bool isTriangle() const { return false; };    

private:
    int radius;
};