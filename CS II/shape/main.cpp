// CS 23001 Spring 2026
// Data Structures and Abstraction
// Lesson on Abstraction, Inheritance and Virtual Methods
// April 8th
// Dr. Maletic
// Max Bird

#include <iostream>
#include "shaoe.hpp"


//v2
int main() {
    shape* tbl[4];

    tbl[0] = new square(2);
    tbl[1] = new triangle(2, 3);
    tbl[2] = new rectangle(5, 7);
    tbl[3] = new circle(3);

    std::cout << "The shapes in tbl: " << std::endl;
    int count = 0;
    // points to shape and returns the shape.draw()
    // static type resolution, determines type of object at compile time
    // needs a virtual method in base class/ good to put in each class that it then effects
    // dynamic type resolution, determines type of object at run time
    // very restricted in c++
    // type resolution delayed until it can be fully resolved
    for(int i = 0; i<4; ++i){
        tbl[i]->draw();
        if(tbl[i]->isRectangle()) ++count;
    }

    std::cout << "Rectangles: " << count << std::endl;
    for(int i=0; i<4; i++){
        delete tbl[i];
    }


}



/*
// v1
int main() {
   rectangle s1(1, 2);
   s1.move(3, 5);
   s1.draw();

   square s2(4);
   s2.move(6, 8);
   s2.draw();

   circle s3(7);
   s3.move(1, 5);
   s3.draw();

   triangle s4(3, 5);
   s4.draw()
}

*/