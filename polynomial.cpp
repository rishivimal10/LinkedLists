#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(int A[], int size) {

    list_ = new DoublyLinkedList;

    for (int i = 0; i < size; i++){
        list_ -> insert_back(A[i]);
    }

    size_ = size;
}

Polynomial* Polynomial::add(Polynomial *rhs) {

    int degree_this = this->size_;
    int degree_rhs = rhs->size_;

    if (degree_this == degree_rhs){
        int A [degree_this];

        for (int i = 0; i < degree_this; i++){
            A[i] = this->list_->select(i) + rhs->list_->select(i);
        }
        Polynomial* sum_ = new Polynomial(A, degree_this);
        return sum_;
    }

    else if (degree_this > degree_rhs){
        int A [degree_this];

        for (int i = 0; i < degree_this; i++){

            if (i < degree_rhs)
                A[i] = this->list_->select(i) + rhs->list_->select(i);
            else
                A[i] = this->list_->select(i);
        }
        Polynomial* sum_ = new Polynomial(A, degree_this);
        return sum_;
    }

    else if (degree_rhs > degree_this){
        int A [degree_rhs];

        for (int i = 0; i < degree_rhs; i++){

            if (i < degree_this)
                A[i] = this->list_->select(i) + rhs->list_->select(i);

            else
                A[i] = rhs->list_->select(i);
        }
        Polynomial* sum_ = new Polynomial(A, degree_rhs);
        return sum_;
    }
}

Polynomial* Polynomial::sub(Polynomial *rhs) {
    int degree_this = this->size_;
    int degree_rhs = rhs->size_;

    if (degree_this == degree_rhs){
        int A [degree_this];

        for (int i = 0; i < degree_this; i++){
            A[i] = this->list_->select(i) - rhs->list_->select(i);
        }
        Polynomial* diff_ = new Polynomial(A, degree_this);
        return diff_;
    }

    else if (degree_this > degree_rhs){
        int A [degree_this];

        for (int i = 0; i < degree_this; i++){

            if (i < degree_rhs)
                A[i] = this->list_->select(i) - rhs->list_->select(i);
            else
                A[i] = this->list_->select(i);
        }
        Polynomial* diff_ = new Polynomial(A, degree_this);
        return diff_;
    }

    else if (degree_rhs > degree_this){
        int A [degree_rhs];

        for (int i = 0; i < degree_rhs; i++){

            if (i < degree_this)
                A[i] = this->list_->select(i) - rhs->list_->select(i);

            else
                A[i] = (-1)*rhs->list_->select(i);
        }
        Polynomial* diff_ = new Polynomial(A, degree_rhs);

        return diff_;
    }
}

Polynomial* Polynomial::mul(Polynomial *rhs) {
    int degree_this = this->size_;
    int degree_rhs = rhs->size_;

    int new_size = degree_rhs+degree_this-1;

    int A [new_size];
    for (int i = 0; i < new_size; i++){
        A[i] = 0;
    }

    for (int i = 0; i < degree_this; i++){
        for (int j = 0; j < degree_rhs; j++){
            A[i+j] += this->list_->select(i)*rhs->list_->select(j);
        }
    }

    Polynomial* prod_ = new Polynomial (A, new_size);
    return prod_;

}

void Polynomial::print() {
    int ctr = -1;
    for (int i = size_ - 1; i >= 0; i--){

        if (ctr == -1 && list_ -> select(i) == 0)
            ctr = i;

        if (ctr != -1 && list_ -> select(i) != 0)
            ctr = -1;
    }

    for (int i = size_ - 1; i >= 0; i--){

        if (list_->select(i) != 0){
            if (list_->select(i) < 0)
                std::cout << "(" << list_->select(i) << ")" << "x^" << i;
            else
                std::cout << list_->select(i) << "x^" << i;

            if (i > ctr + 1)
                std::cout << " + ";
        }
    }
    std::cout << "\n";
}