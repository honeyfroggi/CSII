// Max bird
// Lecture: Feb 18, 2026
// cs23001

#ifndef CS_STACK_HPP
#define CS_STACK_HPP

#include <new>
#include <cassert>

const int STACK_SIZE = 100;

// Lec Mar 2
template <typename T>
class node {
public:
    node() : next(0) {};
    node(const T& item) : data(item), next(0) {};
    T data;
    node<T> *next;
};


template <typename T>
class Stack{
public:
    Stack               () : tos(-1) {};
    ~Stack              ();
    Stack               (const Stack<T>&);
    void      swap      (Stack<T>&);
    Stack<T>& operator= (Stack<T> rhs) { swap(rhs); return *this; };
    bool      isEmpty   () const       { return tos == 0; };
    bool      isFull    () const;
    T         top       () const;
    T         pop       ();
    void      push      (const T&);
private:
    node<T> *tos; // top of stack
};

// Lec Feb 18
//


// template <typename T>
// class Stack{
// public:
//     Stack() : tos(-1) {};
//     bool isEmpty() const { return tos == -1; };
//     bool isFull() const { return tos == STACK_SIZE-1; };
//     void push(const T& item) { assert(!isFull()); s[++tos] = item; };
//     T    pop () { assert(!isEmpty()); return s[tos--]; };
//     T    top () const { assert(!isEmpty()); return s[tos]; };
// private:
//     T s[STACK_SIZE]
//     int tos; // top of stack
// };

template <typename T>
void Stack<T>::push(const T& item) {
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}

template <typename T>
T Stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
Stack<T>::~Stack() {
    node<T> *temp;
    while(tos != 0){
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
Stack<T>::Stack(const Stack<T>& toCopy) : Stack() {
    if(toCopy.tos == 0) return;
    node<T> *temp   = toCopy.tos;
    tos             = new node<T>(temp->data);
    node<T> *bottom = tos;
    temp            = temp->next;
    while(temp != 0){
        bottom->next = new node<T>(temp->data);
        bottom       = bottom->next;
        temp         = temp->next;
    }
}

template <typename T>
void Stack<T>::swap(Stack<T>& rhs) {
    node<T> *temp = tos;
    tos           = rhs.tos;
    rhs.tos       = temp;
}

// when heap is full
template <typename T>
bool Stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node<T>();
    // if new throws BAD_ALLOC (When it runs out of memory) then  nothrow makes it return 0 instead
    if(temp == 0) return true; // Out of memory
    delete temp;
    return false;
}

#endif