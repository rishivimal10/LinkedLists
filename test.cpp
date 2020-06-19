/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include "sequential-list.h"
#include "polynomial.h"
using namespace std;

int main() {

    int A [] = {0, 0, 2};
    int size = 3;

    int C [] = {0,0,0,1};
    Polynomial other (C, 4);
    //other.print();

    int B [] = {0, 0, 0, 5};
    int size2 = 4;
    Polynomial* rhs = new Polynomial (A, size);
    Polynomial* ptr = new Polynomial (B, size2);

    rhs->print();
    ptr->print();


    Polynomial* prod = rhs -> sub(ptr);
    prod -> print();

}