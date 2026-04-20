#include "array.hpp"
#include <cstdlib>

Darray::Darray(int newCap) : Darray() {
    if(newCap > 0){
        cap = newCap;
        ptr = new int[cap];
    }
}

int Darray::operator[](int i) const{
    assert((i>=0) && (i<cap));
    return ptr[i];
}

int& Darray::operator[](int i){
    assert((i>=0) && (i<cap));
    return ptr[i];
}

// Destructor
// cannot call exit()
// does not return anything
Darray::~Darray(){
    delete[] ptr;
}

Darray::Darray(const Darray& toCopy){
    cap = toCopy.cap;
    ptr = new int[cap];
    for(int i = 0; i < cap; ++i){
        ptr[i] = toCopy.ptr[i];
    }
}


// V1 - simple way
Darray& Darray::operator=(const Darray& rhs){
    if(ptr != rhs.ptr){
        delete[] ptr;
        cap = rhs.cap;
        ptr = new int[cap];
        for(int i = 0; i < cap; ++i){
            ptr[i] = rhs.ptr[i];
        }
    }
    return *this;
}

// Constant time swap
void Darray::swap(Darray& rhs){
    int *temp = ptr;
    ptr       = rhs.ptr;
    rhs.ptr   = temp;
    int ctemp = cap;
    cap       = rhs.cap;
    rhs.cap   = ctemp;
}

// Cannonical version of =, prefferesd version
Darray& Darray::operator=(Darray& rhs){
    swap(rhs);
    return rhs;
}

// Resize larger or smaller and copy over contents
void Darray::resize(int newCap){
    int smaller = newCap; // allocate new memory
    if(smaller > cap) smaller = cap;
    int *temp = new int[newCap];
    cap = newCap;
    for (int i = 0; i < smaller; ++i){
        temp[i] = ptr[i];  // copy things over
    }
    delete[] ptr;
    ptr = temp; // reset ptr
}