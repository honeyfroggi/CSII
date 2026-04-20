
#include <iostream>

const int MAP_SIZE = 10;
enum palette {red, blue, green, yellow, none};

class color{
public:
    color () : c(none) {};
    color (palette x) : c(x) {};
    bool operator==(color rhs) const { return c == rhs.c; };
    color& operator++() { c = palette(c + 1); return *this; };

    friend std::ostream& operator<<(std::ostream& out, color hue);

private:
    palette c;
};

class map{
public:
    map ();
    bool isValidColoring(int country, color hue) const;
    void colorCountry (int country, color x) { coloring[country] = x; };
    int  numberOfCountries() const           { return numOfCountries; };

    friend std::ostream& operator<<(std::ostream&, const map&);
    friend std::istream& operator>>(std::istream&, map&);

private: 
    int numOfCountries;
    bool neighbor[MAP_SIZE][MAP_SIZE];
    color coloring[MAP_SIZE];
};


