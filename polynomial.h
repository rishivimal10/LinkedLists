
#ifndef SYDE223_A1_POLYNOMIAL_H
#define SYDE223_A1_POLYNOMIAL_H
#include "doubly-linked-list.h"

class Polynomial {

private:

    int size_;
    DoublyLinkedList* list_;

public:
    Polynomial(int A[], int size);

    Polynomial* add(Polynomial* rhs);

    Polynomial* sub(Polynomial* rhs);

    Polynomial* mul(Polynomial* rhs);

    void print();
};


#endif
