
//
// CLASS INV: ptr-> T(cap)
// REQUIRES: assignable(T) && copyconstructable(T) && destructable(T)
//

#include <cassert>

template <typename T>
class Darray{
public:
    Darray () : ptr(0), cap(0) {};
    Darray (int);
    ~Darray() { delete[] ptr; };
    Darray (const Darray<T>&);

    void       swap(Darray<T>& rhs);
    Darray<T>& operator=(Darray<T> rhs) { swap(rhs); return *this; };
    T          operator[](int i) const { return ptr[i]; }
    T&         operator[](int i) {return ptr[i];}
    void       resize(int)

private:
    T *ptr;
    int cap;
};


template <typename T>
Darray<T>::Darray(int newCap){
    if(newCap > 0){
        cap = newCap;
        ptr = new T[cap];
    }
}

template <typename T>
Darray<T>::Darray(const Darray<T>& toCopy){
    cap = toCopy.cap;
    ptr = new int[cap];
    for(int i = 0; i<cap; ++i){
        ptr[i] = toCopy.ptr[i];
    }
}

template <typename T>
void Darray<T>::swap(Darray<T>& rhs){
    T* temp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = temp;
    int ctemp = cap;
    cap = rhs.cap;
    rhs.cap = ctemp;
}

template <typename T>
void resize(int newCap){
    int smaller = cap;
    if(smaller>newCap) smaller = newCap;
    T *temp = new T[newCap];
    for(int i = 0; i < smaller; ++i){
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
}