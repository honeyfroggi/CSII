


template <typename T>
class dnode{
public:
    dnode() : next(0), prev(0) {};
    dnode(const &T x) : data(x), next(0), prev(0) {};
    T data;
    dnode<T> *next;
    dnode<T> *prev;
};


// REQUIRES: assignable(T) && copyconstructable(T)
template <typename T>
class Itr {
public:
    Itr() : current(0) {};
    Itr(dnode<T> *ptr) : current(ptr) {};

    //                   if(current != 0) same as if(current)
    Itr& operator++()    { if(current) current = current->next; return *this; };  // ++i
    Itr  operator++(int) { Itr<T> original(current); if(current) current = current->next; return original; };  // i++
    Itr& operator--()    { if(current) current = current->prev; return *this; };  // --i
    Itr  operator--(int) { Itr<T> original(current); if(current) current = current->prev; return original; };  // i--
    // ++(++i)      fine: returns 7
    // (i++)++      ehh: probably not fine, maybe returns 6, probably an error

    bool operator==(Itr<T> rhs) { return current == rhs.current; };
    bool operator!=(Itr<T> rhs) { return current != rhs.current; };
    T&   operator* ()           { return current->data; };
    T    operator* () const     { return current->data; };
    // Overloading ->
    // Must be a member, returns a pointer or an object if the class
    // ptr->data = 10;
    // (ptr.operator()->)->data = 10;
    dnode<T>*       operator->()       { return current; };
    const dnode<T>* operator->() const { return current; };

    friend class List<T>;

private:
    dnode<T> *current;
};

// CLASS INV: (beginning == 0 && ending == 0 ) ||
//             beginning -> X[0] <-> X[1] <-> ...
//                          <-> X[length()-1 ] <- ending
//
template <typename T>
class List {
public:
    List() : beginning(0), ending(0) {};
    ~List();
    List(const List<T>&);
    void swap(List<T>&);
    List<T>& operator=(List<T> rhs) {swap(rhs); return *this; };

    bool  isEmpty() const { return beginning == 0; };
    bool  isFull() const;
    int   length() const;

    const  Itr<T> begin() const { return Itr<T>(beginning); };
    Itr<T>        begin()       { return Itr<T>(beginning); };
    const  Itr<T> end() const   { return Itr<T>(ending);    };
    Itr<T>        end()         { return Itr<T>(ending);    };

    const  Itr<T> operator[](int i) const;
    Itr<T>        operator[](int i);
    Itr<T> find(const T& key) const;
    Itr<T>        find(const T& key);

    // REQUIRES: non zero 
    T            front() const { return beginning->data; };
    T&           front()       { return beginning->data; };
    T            back () const { return ending->data;    };
    T&           back ()       { return ending->data;    };

    void insertBefore(Itr<T>, const T&);
    void insertAfter(Itr<T>, const T&);
    void remove(Itr<T>);

private:
    dnode<T> *beginning, *ending;
};


template <typename T>
Itr<T> List<T>::find(const T& key) const {
    Itr<T> i = begin();
    while(i != 0) { 
        if(*i == key) return i;
        ++i;
    }
    return Itr<T>(0);
}

template <typename T>
Itr<T> List<T>::find(const T& key) {
    Itr<T> i begin();
    while((i != 0) && (*i != key)) ++i;
    return i;
}

template <typename T>
Itr<T> List<T>::operator[](int i){
    if(isEmpty()) return Itr<T>(0);
    Itr<T> result = beginning;
    int j = 0;
    while(result != 0){
        if(j == i) return result;
        ++result;
        ++j;
    }
    return Itr<T>(0);
}

template <typename T>
List<T>::~List(){
    dnode *temp;
    while (beginning){
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

template <typename T>
List<T>::List(const List<T>& toCopy){
    if (toCopy.beginning == 0) return;
    ITr<T> temp = toCopy.beginning;
    beginning = new dnode<T>(*temp);
    ending = beginning;
    ++temp;
    while(temp != 0){
        ending->next = new dnode<T>(*temp);
        ending->next->prev = ending;
        ending = temp.current;
        ++temp;
    }
}

// REQUIRES: ptr -> 2x &&
//           beginning -> x1 <-> x2 <-> x3 <-> ... <-> xN <- ending
// ENSURES:  beginning -> x1 <-> item <-> x2 <-> x3 <-> ... <-> xN <- ending
template <typename T>
void List<T>::insertBefore(Itr<T> ptr, const T& item) {
    if(beginning == 0){
        beginning = new dnode<T>(item);
        ending    = beginning;
    } else if (ptr == beginning) { // EXAM QUESTION: ptr == beginning? can a pointer be comapared to an iterater? YES
        beginning->prev = new dnode<T>(item);
        ptr->prev->next = beginning;            // ptr.current->prev->next  
        beginning       = beginning->prev;
    } else {                                    // insert in the middle
        dnode<T> *temp = new dnode<T>(item);
        temp->next      = ptr.current;          // List is friend of Itr so it can get a private
        temp->prev      = ptr->prev;
        ptr->prev->next = temp;
        ptr->prev       = temp;
    }

}


template <typename T>
void List<T>::insertAfter(Itr<T> ptr, const T& item){
    dnode *temp = new dnode<T>(item);
    if(beginning == 0){
        beginning = temp;
        ending = temp;
    } else if (ptr == ending) { // insert after ending
        ending->next = temp;
        ending->prev = ending;
        ending = temp;
    } else {
        temp->nextt     = ptr->next;
        temp->prev      = ptr.current;
        ptr->next->prev = temp;
        ptr->next       = temp;
    }
}

// REQUIRES: !isEmpty() && ptr-> x2
//           beginning -> x1 <-> x2 <-> x3 <-> ... <-> xN <- ending
// ENSURES:  beginning -> x1 <-> x3 <-> ... <-> xN <- ending
template <typename T>
void List<T>::remove(Itr<T> ptr){
    if(ptr == beginning){
        beginning = beginning->next;
    } else {
        ptr->prev->next = ptr->next;
    }
    if(ptr == ending){
        ending = ending->prev;
    } else {
        ptr->next->prev = ptr->prev;
    }
    delete ptr.current;
}

template <typename T>
void List<T>::swap(List<T>& rhs){
    dnode<T> *temp = beginning;
    beginning = rhs.beginning;
    rhs.beginning = temp;
    temp = ending;
    ending = rhs.ending;
    rhs.ending = temp;
}

