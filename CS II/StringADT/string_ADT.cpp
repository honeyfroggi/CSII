#include "string_ADT.hpp"
#include <iostream>

String::String(){
    str[0] = 0;    // Empty String
}

String::String(char ch){
    str[0] = ch;
    str[1] = 0;
}

String::String(const char value[]){
    int i = 0;
    while(value[i] != 0){
        str[i] = value[i];
        ++i;
    }
    str[i] = 0;    // null terminator
}

int String::length() const {
    int len = 0;
    while(str[len] != 0) ++len;
    return len;
}

// REQUIRES: 0 <= i < length()
char String::operator[](int i) const{
    assert((i>=0) && (i<length()));     // Error handling for negative numbers
    return str[i];
}

char& String::operator[](int i){
    assert((i>=0) && (i<length()));     // Error handling for negative numbers
    return str[i];
}

// REQUIRES: length() + rhs.length() <= capacity()
String String::operator+(const String& rhs) const{  // V1
    String result(str);  // result contains the lhs of equation (str)
    int offset = length(); // this.length() == length()
    int i = 0;
    while(str[i] != 0){
        if((offset + i) >= capacity()) break;
        result.str[i + offset] = rhs.str[i];
        ++i;
    }
    result.str[offset + i] = 0;  //null terminator
    return result;
}

// V1
// String operator+(const char lhs[], const String& rhs){
//     return String(lhs) + rhs;
// }

// String operator+(char lhs, const String& rhs){
//     return String(lhs) + rhs;
// }

// V2
String& String::operator+=(const String& rhs){
    int offset = length();
    int rhsLen = rhs.length();
    int i;
    for(i = 0; i < rhsLen; ++i){
        if((offset + i) >= capacity()) break;
        str[offset+i] = rhs.str[i];
    }
    str[offset+i] = 0;
    return *this;
}

String operator+(String lhs, const String& rhs){
    return lhs += rhs;
}

// "ABC" == "ABC"
// "ABC" != "ABCD"
bool String::operator==(const String& rhs) const{
    int i = 0;
    while((str[i] != 0 && rhs.str[i] != 0) && (str[i] == rhs.str[i])){
        ++i;
    }
    return str[i] == rhs.str[i];      // returns true or false depending on if the ends of the arrays match 0 == 0
}

// "A" < "B"
// "ABC" < "ABCD"
// "A" < "BBBB"
// "ABCD" < "ABCFD"
// "BB" !< "AA"
// "AA" !< "AA"
bool String::operator<(const String& rhs) const{
    int i = 0;
    while((str[i] != 0 && rhs.str[i] != 0) && (str[i] == rhs.str[i])){
        ++i;
    }
    return str[i] < rhs.str[i];
}

bool operator==(const char lhs[],  const String& rhs) { return String(lhs) == rhs; }
bool operator==(char lhs,          const String& rhs) { return String(lhs) == rhs; }
bool operator< (const char lhs[],  const String& rhs) { return String(lhs) < rhs;  }
bool operator< (char lhs,          const String& rhs) { return String(lhs) < rhs;  }
bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator<=(const String& lhs, const String& rhs) { return !(rhs < lhs);  }
bool operator>=(const String& lhs, const String& rhs) { return !(lhs < rhs);  }
bool operator> (const String& lhs, const String& rhs) { return rhs < lhs;     }

// RQUIRES: 0 <= start <= end < length()
String String::subString(int start, int end) const{
    String result;
    if(start < 0) start = 0;
    if(end >= length()) end =length()-1;
    if(start > end) return result;
    int i;
    for(i = start; i <= end; ++i){
        result += str[i];
    }
    return result;
}

// RQUIRES: 0 <= start < length()
// ENSURES: RETVAL = i where str[i] == key && i >= start  ||
//          RETVAL == -1 where key not in str[start, ..., length()-1] 
int String::findChar(int start, char key) const{
    if(start < 0) start = 0;
    if(start >= length()) return -1;
    int i = start;
    while(str[i] != 0){
        if(str[i] == key) return i;
        ++i;
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
    out << rhs.str;
    return out;
}

// useful for fileio and bigint 
std::istream& operator>>(std::istream& in, String& rhs){
    char buffer[STRING_SIZE];
    buffer[0] = 0;
    if(!in.eof()) in >> buffer;
    rhs = String(buffer);

    return in;
}