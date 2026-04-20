//
// btreeV2.hpp
// Spring 2026 CS23001
// Dr. Johnathan Maltic
// Week of March 28
//
// Max Bird
//

#ifndef BTREEV2_HPP_CS
#define BTREEV2_HPP_CS

#include <iostream>

//
// Binary Search trees
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

// BST can have an issue of being unbalanced


//
// Balanced Trees: 2-3-4 trees (Developed in the 60s):
//                 A-V-L trees 
// 2-3-4 Trees: (Developed ~60s)
//              always height balanced
//              left subtree = smaller val, right = larger
//              nodes have 1-3 values
//              each node has 1-4 children
//    2-node            3-node                 4-node
//     (5)             (10 < 20)            (10 < 20 < 30)
//     / \            /    |   \            /   |    |    \ 
//    (3)(6)        (5)   (15) (25)       (5)  (15) (25)  (35)
//
//
//         Insertion: add elements until node is full
//                    4-node+1 val split into three 2-nodes
//                    then insert
//
//      (10, 20, 30)                            (20)
//     /   |    |   \       ------->            /  \ 
//   (5) (15)  (25)  (35)                     (10) (30)
//                                           /  \   / \ 
//                                         (5)(15) (25)(35)


template <typename T>
class bnode{
public:
    bnode() : next(0), prev(0) {};
    bnode(const &T x) : data(x), next(0), prev(0) {};
    bnode(const bnode<T>&);
    ~bnode();
    bool find(const T&) const;
    void binsert(const T&);
    bnode<T>* bremove(const T&);
    T predecessor() const;
    void inorder(std::osteam&) const;


private:    
    T data;
    bnode<T> *left;
    bnode<T> *right;
};

template <typename T>
class btree{
public: 
    btree() : root(0) {};
    btree(const btree<T>&);
    ~btree();
    void swap(btree<T>&);
    btree<T> operator(btree<T> rhs) { swap(rhs); return *this; };
    bool isEmpty() const { return root; };
    bool isFull() const;
    void binsert(const T&);
    bool find(const T&) const;
    void bremove(const T&);
    void inorder(std::ostream&) const;

private:
    bnode<T> *root;
};

template <typename T>
void bnode<T>::binsert(const T& item){
    if(item < data){
        if (left) left->binsert(item);
        else left = new bnode<T>(item);
    } else {
        if(item == data) return;
        if (right) right->binsert(item);
        else right = new bnode<T>(item);
    }
}

template <typename T>
void btree<T>::binsert(const T& item){
    if(!root) root = new bnode<T> item;
    else root->binsert(item);

}

// calls the bnode find, so its fine that there
// is no return true statement in this function, 
// its in the bnode function
template <typename T>
bool btree<T>::find(const T& key) const{
    if (root){
        return root->find(key);    
    } else {
        return true;
    }
}

template <typename T>
bool bnode<T>::find(const T& key) const{
    if(key == data) return true;
    if(key < data) {
        if (left) return left->find(key);
        else return false;
    } else {
        if (right) return right->find(key);
        else return false;
    }
}

template <typename T>
T bnode<T>::predecessor() const{
    if (right) return right->predecessor();
    return data;
}

template <typename T>
void btree<T>::bremove(const T& key){
    if(root) root = root->bremove(key);
}

template <typename T>
bnode<T>* bnode<T>::bremove(const T& key){
    if(key == data){  // need to remove bnode
        if(!left && !right) { // no children/ leaf node
            delete this;
            return 0;
        } 
        if (!left && right) { // only right child
            bnode<T>* rightChild = right;
            // delete this; would delete the subtree after this so:
            right = 0;  // short circuts the ptr and this no longer points to right
            delete this;
            return rightChild;
        }
        if (left && !right) { // only right child
            bnode
            return 0;
        }
       // have two children
       data = left->predecessor();
       left = left->bremove(data);
    } else if (key < data){
        if (left) left = left->bremove(key);
    } else {
        if(right) right = right->bremove(key);
    }
    return *this;
}


template <typename T>
btree<T>::~btree(){
    if(root) delete root;
}

template <typename T>
bnode<T>::~bnode(){
    if(left) delete left;
    if(right) delete right;
    // Complier cleans up the rest of *this
}

template <typename T>
btree<T>::btree(const btree<T>& toCopy) : btree() {
    if(toCopy.root) root = new bnode<T>(*(toCopy.root));
}

template <typename T>
bnode<T>::bnode(const bnode<T>& toCopy) : bnode() {
    // preorder traversal
    data = toCopy.data;
    if(toCopy.left) left = new bnode<T>(*(toCopy.left));
    if(toCopy.right) right = new bnode<T>(*(toCopy.right));
}

#endif