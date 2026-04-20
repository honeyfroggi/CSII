#include "set.hpp"
#include <iostream>

bool isValid(int a){
    return (0 <= a) && (a<DOMAIN_SIZE);
}

Set::Set(){
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        element[i] = false;
    }
}

Set::Set(int a){
    if(isValid(a)) element[a] = true;
}

Set::Set(int a, int b){
    if(isValid(a)) element[a] = true;
    if(isValid(b)) element[b] = true;
}

int Set::cardinality(){
    int result = 0;
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        if(element[i]) ++result;
    }
    return result;
}

// Union
Set Set::operator+(const Set& rhs) const {
    Set result;
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        result.element[i] = element[i] || rhs.element[i];
    }
    return result;
}

// Intersection
Set Set::operator*(const Set& rhs) const {
    Set result;
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        result.element[i] = element[i] && rhs.element[i];
    }
    return result;
}

Set Set::operator-(const Set& rhs) const {
    Set result;
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        result.element[i] = element[i] && !rhs.element[i];
    }
    return result;
}

// REQUIRES 0 < i < DOMAIN_SIZE
bool Set::operator[](int i) const {
    if(isValid) return element[i];
    return false;
}

bool Set::operator==(const Set& rhs) const {
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        if(element[i] != rhs.element[i]) { return false; }
    }
    return true;
}

bool Set::operator<=(const Set& rhs) const {
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        if(element[i] && !rhs.element[i]) { return false; }
    }
    return true;
}

Set operator+ (int lhs, const Set& rhs) { return Set(lhs) + rhs; }
Set operator* (int lhs, const Set& rhs) { return Set(lhs) * rhs; }
Set operator- (int lhs, const Set& rhs) { return Set(lhs) - rhs; }
Set operator==(int lhs, const Set& rhs) { return Set(lhs) == rhs; }
Set operator<=(int lhs, const Set& rhs) { return Set(lhs) <= rhs; }
Set operator>=(const Set& lhs, const Set& rhs) { return rhs <= lhs; }
Set operator!=(const Set& lhs, const Set& rhs) { return !(rhs == lhs); }

std::istream& operator>>(std::istream in, const Set& set) {
     
}

std::ostream& operator<<(std::ostream out, const Set& rhs){
    out << "{";
    bool printComma = false;
    for(int i = 0; i < DOMAIN_SIZE; ++i){
        if(rhs[i]){
            printComma = true;
        }
        if(printComma){
            out << ", ";
        }
        out << i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Set& rhs){
    int temp;
    rhs = Set();
    while(!in.eof()){
        in >> temp;
        rhs = rhs + Set(temp);
    }
    return in;
}

Set::Set(std::initializer_list<int> lst) : Set() {
    for(int i : lst){
        if(isValid(i)) element[i] = true;
    }
}