
#include <iostream>

// Factorial
int nfact (int n){
    if(n <= 1){
        return 1;
    }else{
        return n * nfact(n-1);
    }
}


/*

nfact(5) : return 5 *nfact(4);
nfact(4) : return 4 *nfact(3);
nfact(2) : return 3 *nfact(2);
nfact(2) : return 2 *nfact(1);
nfact(1) : return 1;

nfact(2) return 2 * 1;
nfact(3) return 3 * 2;
nfact(4) return 4 * 6;
nfact(5) return 5 * 24;
= 120

*/


// Fibonacci Sequence
int fib(int n){
    if(n<=2){
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }
}

/*
fib(5) : return fib(4) + fib(3);          (3 + 2)
    fib(4) : return fib(3) + fib(2);      (2 + 1)
        fib(3) : return fib(2) + fib(1);  (1 + 1)
            fib(2) : return 1;

Not efficent
Wouldn't write a fibonacci recursively, 
maps well but not hardware efficient
Iterative versions are more efficient 

*/

enum poleName {left, right, middle};

class pole{
public:
    pole() {};
    pole(poleName x ) : p(x) {};
    friend std::ostream& operator<<(std::ostream& out, pole rhs);
private:
    poleName p;
};

std::ostream& operator<<(std::ostream& out, pole rhs){
    switch(rhs.p){
        case left: out << "left"; break;
        case right: out << "right"; break;
        case middle: out<< "middle"; break;
    }
    return out;
}

void move(int n, pole src, pole temp, pole dest){
    if(n <= 1){
        std::cout << "Move disk form " << src << " to " << dest << std::endl;
    } else{
        move(n-1, src, dest, temp);
        std::cout << "Move disk form " << src << " to " << dest << std::endl;
        move(n-1, temp, src, dest);
    }
}

int main () {
    int n = 1;
    std::cout << "towers of hanoi" << std::endl;
    std::cout << "How many disks? ";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << "To solve rhe towers of hanoi with " << n << " disks, make the following moves" << std:: endl;

    move(n, left, middle, right);
}