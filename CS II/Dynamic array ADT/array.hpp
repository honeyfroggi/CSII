#include <iostream>
#include <cassert>

class Darray{
public: 
    Darray  () : ptr(0), cap(0) {};
    Darray  (int);
    Darray  (const Darray&);  // Copy construct
    ~Darray ();              // Deconstruct
    void    swap     (Darray&);     // Constant time swap
    Darray& operator=(const Darray&);   // V1
    Darray& operator=(Darray&);        // V2 - preferred

    int capacity() const {return cap; }

    int operator[]  (int) const;
    int& operator[] (int);
    void resize(int);
    
private:
    int *ptr;
    int cap;
};