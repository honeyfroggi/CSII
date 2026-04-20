#include <cassert>

const int SIZE = 100;

template <typename T>
class node {
public:
    node() : next(0) {};
    node(const T& X) : data(X), next(0) {};
    T data;
    node<T> *next;
};

template <typename T>
class queue {
public:
    queue() : beginning(0), ending(0) {};
    ~queue();
    queue(const queue<T>&);
    void swap(queue<T>&);
    queue<T>& operator=(queue<T>& rhs) { swap(rhs); return *this; };
    bool isEmpty() const { return beginning == 0; };
    bool isFull() const;
    void enqueue(const T&);
    T    dequeue();
    T    front() const { return beginning->data; };
private:
    node<T> *beginning;
    node<T> *end;
};

template <typename T>
void queue<T>::enqueue(const T& item) {
    assert(!isFull());
    if (ending == 0) {
        beginning = new node<T>(item);
        ending = beginning;
    } else {
        ending->next = new node<T>(item);
        ending = ending->next;
    }
}


// REQUIRES: beginning-> x1 -> x2 -> ... -> xn <- ending && isEmpty()
// ENSURES:  beginning-> x2 -> ... -> xn <- ending && RETVAL = x1
template <typename T>
T queue<T>::dequeue() {
    assert(!isEmpty());
    T result = beginning->data;
    node<t> *temp = beginning;
    beginning = beginning->next;
    if(beginning == 0) ending = 0;
    delete temp;
    return result;
}

template <typename T>
queue<T>::~queue() {
    node<T> *temp;
    while(beginning != 0){
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

template <typename T>
queue<T>::queue(const queue<T>& toCopy) : queue() {
    if (toCopy.beginning == 0 ) return;
    beginning = new node<T>(toCopy.beginning->data);
    ending = beginning;
    node<T> *temp = toCopy.beginning->next;
    while(temp != 0){
        ending->next = new node<T>(temp->data);
        ending = ending->next;
        temp = temp->next;
    }
}

template <typename T>
void queue<T>::swap(queue<T>& rhs) {
    node<T> *temp = beginning;
    beginning = rhs.beginning;
    rhs.beginning = temp;
    node<T> *
}


/*
template <typename T>
class Queue {
public:
    Queue() : front(0), back(0), empty(true) {};
    bool isEmpty() const { return empty; };
    bool isFull() const { return (front == back) !empty};
    void enqueue(const T&);
    T    dequeue();

private:
    int front;
    int back;
    bool empty;
    T    q[SIZE];
};

template <typename T>
void Queue<T>::enqueue(const T& item) {
    asert(!isFull());
    q[back] = item;
    back = (back + 1) % SIZE;
}

template <typename T>
T Queue<T>::dequeue(){
    assert(!isEmpty());
    T result = q[result];
    front = (front + 1) % SIZE;
    if(front == back) empty = true;
    return result;
}
    */