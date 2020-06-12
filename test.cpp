/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include "sequential-list.h"
#include "doubly-linked-list.cpp"
using namespace std;

int main() {

    DoublyLinkedList *list = new DoublyLinkedList();

    list -> insert_back(1);
    list -> insert(5, 0);
    list -> insert(7, 0);
    list -> insert(1, 0);
    list -> insert(3, 0);
    list -> insert(2, 0);
    list -> insert(8, 6);
    list -> remove_back();
    //list -> insert_front(4);
    //list -> insert_back(9);
    //list -> insert_front(6);
    //list -> remove(9);
    //list -> replace(3, 5);

    cout << list -> search(2);
    cout << "\n";
    cout << list -> select(1);
    cout << "\n";
    cout << list -> size();
    cout << "\n";
    list -> print();
    delete list;
    list = NULL;
}