

#include "map.hpp"
#include <fstream>
#include <iostream>


bool MapColor(int country, map& world){
    if (country  >= world.numberOfCountries()){
        return true;
    } else {
        bool doneColoring = false;
        bool aColorRemains = true;
        color hue = red;
        while(aColorRemains && !doneColoring){
            if(world.isValidColoring(country, hue)){
                world.colorCountry(country, hue);
                doneColoring = MapColor(country+1, world);
            }
            if(hue == yellow) aColorRemains = false;
            else ++hue;
        }

        if(!doneColoring) world.colorCountry(country, none);

        return doneColoring;
    }
}



int main() {
    map world;

    std::ifstream in("map1.txt");
    in >> world;
    MapColor(0, world);
    std::cout << world;
    //std::cout << 

}

std::ostream& operator<<(std::ostream& out, color hue) {
    switch(hue.c){
        case red: out << "red"; break;
        case blue: out << "blue"; break;
        case yellow: out << "yellow"; break;
        case green: out << "green"; break;
        case none: out << "none"; break;
    }
    return out;
}