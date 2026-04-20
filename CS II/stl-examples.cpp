//
//  STL examples
//
//  Created by Jonathan Maletic
//  Copyright 2023 Kent State University. All rights reserved.
//  Fall 2023
//
//  Compile with:
//  clang++ -std=c++11 -Wall -std=c++17 stl-examples.cpp


#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

bool greater10( int value ) {
    return value > 10;
}                        

int main() {

    //vector
    {
        std::cout << "Vector =========================" << std::endl;
        std::vector<int> v;
        std::cout << "The initial size of v is: " << v.size()
                  << "\nThe initial capacity of v is: " << v.capacity();

        v.push_back( 2 );  v.push_back( 3 );  v.push_back( 4 );
        std::cout << "\nThe size of v is: " << v.size()
                  << "\nThe capacity of v is: " << v.capacity();

        std::cout << "\n\nContents of vector v a using array notation: ";
        for (int i=0; i<v.size(); ++i) {
            std::cout << v[i] << " ";
        }

        std::cout << "\nContents of vector v using iterator notation: ";
        for (std::vector<int>::const_iterator p1 = v.begin();
             p1 != v.end(); p1++) {
            std::cout << *p1 << " ";
        }

        std::cout << "\nReversed contents of vector v: ";
        std::vector<int>::reverse_iterator p2;
        for (p2 = v.rbegin(); p2 != v.rend(); ++p2) {
            std::cout << *p2 << " ";
        }

        std::cout << std::endl;
    }

    //List
    {
        std::cout << "List =========================" << std::endl;
        std::list<int> lst;
        lst.push_back(10); lst.push_back(20);
        lst.push_back(30); lst.push_back(40);
        for (std::list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;

        std::list<int>::iterator ptr = lst.begin();
        ++ptr; ++ptr;
        lst.insert(ptr, 100);
        for (std::list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }


    //Map
    {
        std::cout << "Map =========================" << std::endl;

        std::map<std::string, int> tbl;
        tbl["joe"] += 1;
        tbl["joe"] += 1;
        tbl["sue"] += 1;
        tbl["jon"] += 1;
        tbl["sue"] += 1;
        tbl["fred"] += 1;

        for(std::map<std::string, int>::const_iterator i = tbl.begin(); i != tbl.end(); ++i) {
            std::cout << i->first << " " << i->second << std::endl;
        }
    }

    //Set
    {
        std::cout << "Set =========================" << std::endl;

        typedef std::set<double, std::less<double>> double_set;
        const int SIZE = 5;
        double a[SIZE] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
        double_set doubleSet(a, a + SIZE);;

        std::ostream_iterator<double> output(std::cout, " ");
        std::cout << "doubleSet contains: ";
        std::copy(doubleSet.begin(), doubleSet.end(), output);

        std::pair<double_set::const_iterator, bool> p;
        p = doubleSet.insert( 13.8 ); // value not in set
        std::cout << '\n' << *( p.first ) << ( p.second ? " was" : " was not" ) << " inserted";
        std::cout << "\ndoubleSet contains: ";

        std::copy(doubleSet.begin(), doubleSet.end(), output);
        p = doubleSet.insert( 9.5 );  // value already in set
        std::cout << '\n' << *( p.first ) << ( p.second ? " was" : " was not" ) << " inserted";
        std::cout << "\ndoubleSet contains: ";

        std::copy(doubleSet.begin(), doubleSet.end(), output);
        std::cout << std::endl;
    }

    //Unordered Set
    {
        std::cout << "Unordered Set =========================" << std::endl;

        //Great for global tables of information.  Very fast lookup.
        //
        const std::unordered_set<std::string> TYPED_CATEGORIES = {
            "local",
            "global",
            "field",
            "typedef",
            "parameter",
            "function",
            "function_decl",
            "event",
            "property"
        };

        if (TYPED_CATEGORIES.find("parameter") != TYPED_CATEGORIES.end())
            std::cout << "Is in typed category" << std::endl;
        else
            std::cout << "Is NOT in typed category" << std::endl;
    }


    //Algorithms - Sorted Sequence
    {
        std::cout << "Algorithms =========================" << std::endl;

        const int SIZE = 10;
        int       a[ SIZE ] = { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };

        std::vector<int>           v( a, a + SIZE );
        std::ostream_iterator<int> output( std::cout, " " );

        std::cout << "Vector v contains: ";
        std::copy( v.begin(), v.end(), output );

        std::vector< int >::iterator location;
        location = std::find( v.begin(), v.end(), 16 );
        if ( location != v.end() )
            std::cout << "\nFound 16 at location " << ( location - v.begin() );
        else
            std::cout << "\n16 not found";

        location = std::find( v.begin(), v.end(), 100 );
        if ( location != v.end() )
            std::cout << "\nFound 100 at location " << ( location - v.begin() );
        else
            std::cout << "\n100 not found";

        location = std::find_if( v.begin(), v.end(), greater10 );
        if ( location != v.end() )
            std::cout << "\nThe first value greater than 10 is "
                    << *location << "\nfound at location "
                    << ( location - v.begin() );
        else
            std::cout << "\nNo values greater than 10 were found";

        std::sort( v.begin(), v.end() );
        std::cout << "\nVector v after sort: ";
        std::copy( v.begin(), v.end(), output );
        if ( std::binary_search( v.begin(), v.end(), 13 ) )
            std::cout << "\n13 was found in v";
        else
            std::cout << "\n13 was not found in v";

        if ( std::binary_search( v.begin(), v.end(), 100 ) )
            std::cout << "\n100 was found in v";
        else
            std::cout << "\n100 was not found in v";

        std::cout << std::endl;
    }

    return 0;
}





