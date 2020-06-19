/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include "sequential-list.h"
#include "polynomial.h"
using namespace std;

int main() {

    int A [] = {-9, 1};
    int size = 2;

    int B [] = {9, 1};
    int size2 = 2;
    Polynomial* rhs = new Polynomial (A, size);
    Polynomial* ptr = new Polynomial (B, size2);


    Polynomial* prod = rhs -> mul(ptr);
    prod -> print();

}