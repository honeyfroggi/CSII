#include <cassert>

#include <iostream>



const int STRING_SIZE = 100;

//
// CLASS INV: 
//
//
//
//

class String{
public:
        String();
        String(char);
        String(const char[]);
    int capacity() const { return STRING_SIZE-1; };
    int length() const;

    char    operator[](int)                 const;
    char&   operator[](int);
    String  operator+ (const String&)       const;       // Concatination V1
    String& operator+=(const String&);
    bool    operator==(const String&)       const;
    bool    operator< (const String&)       const;
    String  subString (int start, int end)  const;
    int     findChar  (int start, char key) const;

    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    char str[STRING_SIZE];
};

std::istream& operator>>(std::istream&, String&);

String operator+(const char[], const String&);  // V1
String operator+(char, const String&);          // V1

String operator+(String, const String&);        // V2

bool operator==(const char[], const String);
bool operator==(char, const String);
bool operator< (const char[], const String);
bool operator< (char, const String);
bool operator!=(const char[], const String);
bool operator<=(const char[], const String);
bool operator> (const char[], const String);
bool operator>=(const char[], const String);


