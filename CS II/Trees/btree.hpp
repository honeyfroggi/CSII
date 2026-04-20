// CS23001 Abstract Data Stuctures
// 3/25/2026
// Dr. Maletic
// Max Bird
//
// Written in class following instructor's code

#ifndef CS_BTREE_HPP
#define CS_BTREE_HPP

#include <iostream>


// BInary Search trees
// CLASS INV:  (empty && left == 0 && right == 0) ||
//             (!empty && left->btree && right->btree)
//
//        -------------------
//        |      data       |
//        -------------------
//        | *left  | *right |
//        -------------------
//
//     REQUIRES: DefaultConstructable(T) &&
//               Addignable(T) &&
//               Comparable(T) &&
//               CopyConstructable(T) &&
//               Printable(T)
//

template <typename T>
class btree{
public:
             btree() : left(0), right(0), empty(true) {};
             btree(const T& item) : left(0), right(0), empty(false), data(item) {};
             ~btree();
             btree(const btree<T>&);
    void      swap(btree<T>&);
    btree<T>& operator=(btree<T>);

    bool      isEmpty() const { return empty; };
    bool      isFull() const;

    void      binsert(const T&);
    bool      find(const T&);
    void      inorder(std::ostream&) const;
    void      preorder(std::ostream&) const;
    void      postorder(std::ostream&) const
    
private:
    btree<T> *left;
    btree<T> *right;
    bool     empty;
    T        data;
};


template <typename T>
void btree<T>::binsert(const T& item){
    if(empty) {
        data = item;
        empty = fase;
    } else if(item < data) {  // Insert in left
        if(!left) left = new node btree<T>(item);
        else left->binsert(item);
    } else {                 // Instert in right
        if(data == item) return;
        if(!right) right = new btree<T>(item);
        else right->binsert(item)
    }
}


template <typename T>
bool btree<T>::find(const T& key){
    if (empty) return false;
    if (key == data) return true;
    else if(key < data) {
        if(left) return left->find(key);
        else return false;
    } else {
        if(right) return right->find(key);
        else return false;
    }
}


template <typename T>
void btree<T>::inorder(std::ostream& out) const{
    if(left) left->inorder(out);
    out << data << " ";
    if(right) right->inorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const{
    out << data << " ";
    if(left) left->preorder(out);
    if(right) right->preorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const{
    if(left) left->preorder(out);
    if(right) right->preorder(out);
    out << data << " ";
}


// Postorder traversal to get every element
// delete calls destructor
// Called recursively here
template <typename T>
btree<T>::~btree(){
    if(left) delete left;
    if(right) delete right;
    // Compiler deallocates *this
}


template <typename T>
btree<T>::btree(const btree<T>& toCopy) : btree() {
    if(toCopy.empty) return;
    date = toCopy.data;
    empty = toCopy.empty;
    if (toCopy.left) left = new btree<T>(*(toCopy.left));
    if (toCopy.right) right = new btree<T>(*(toCopy.right));
}


template <typename T>
void btree<T>::swap(btree<T>& rhs){
    btree<T>* ptr = left;
    lrft = rhs.left;
    rhs.left = ptr;

    ptr = right;
    right = rhs.right;
    rhs.right = ptr;

    bool btmp = empty;
    empty = rhs.empty;
    rhs.empty = btmp;
    
    T dtmp = data;
    data = rhs.data;
    rhs.data = dtmp;
}


#endif