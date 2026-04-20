

#include <iostream>
#include "map.hpp"

map::map(){
    for(int i = 0; i <MAP_SIZE; i++){
        coloring[i] = none;
        for(int j = 0; j < MAP_SIZE; j++)neighbor[i][j] = false;
    }
}

// REQUIRES: <none>
// ENSURES: Retval TRUE if no adjacent country is the same color
bool map::isValidColoring(int country, color hue) const{
    for (int i = 0; i < numOfCountries; i++){
        if(neighbor[country][i] && (hue == coloring[i]))
            return false;
    }
    return true;
}


std::ostream& operator<<(std::ostream& out, const map& m){
    int i;
    out << "Number of Countries" << m.numOfCountries << std::endl;
    for (i = 0; i < m.numOfCountries; i++){
        out << "Country: " << i << " is " << m.coloring[i] << std::endl;
    }
}

std::istream& operator>>(std::istream& in, map& m){
    in >> m.numOfCountries;
    for (int i = 0; i < m.numOfCountries; i++){
        for(int j = 0; j < m.numOfCountries; j++){
            int temp;
            in >> temp; std::cout << temp;
            if (temp == 1) m.neighbor[i][j] = true;
            else           m.neighbor[i][j] = false;
        }
        std::cout << std::endl;
    }
    return in;
}