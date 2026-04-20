#ifndef CS_SET_HPP
#define CS_SET_HPP

#include <iostream>

const int DOMAIN_SIZE = 100;

class Set{
public:
    Set();
    Set(int);
    Set(int, int);
    Set(std::initializer_list<int>);

    int cardinality();
    bool operator[](int) const;
    Set operator+  (const Set&) const;
    Set operator*  (const Set&) const;
    Set operator-  (const Set&) const;
    bool operator==(const Set&) const;
    bool operator<=(const Set&) const;
    bool operator< (const Set&) const;
private:
    bool element[DOMAIN_SIZE];
};

std::istream& operator>>(std::istream&, Set&);
std::ostream& operator<<(std::ostream&, const Set&);

Set operator+ (int, const Set&);
Set operator* (int, const Set&);
Set operator- (int, const Set&);
Set operator==(int, const Set&);
Set operator<=(int, const Set&);
Set operator!=(const Set&, const Set&);
Set operator>=(const Set&, const Set&);

#endif