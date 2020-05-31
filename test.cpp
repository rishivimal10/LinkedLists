/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include "sequential-list.h"
using namespace std;

int main() {

    SequentialList *list = new SequentialList(10);

    list -> insert(5, 0);
    list -> insert(7, 0);
    list -> insert(1, 0);
    list -> insert(3, 0);
    list -> insert(2, 0);
    list -> insert(8, 2);
    list -> insert_front(4);
    list -> insert_back(9);
    list -> insert_front(6);
    list -> insert_front(0);
    list -> insert_front(20);
    //list -> replace(9, 5);

    cout << list -> search(2);
    cout << "\n";
    cout << list -> select(0);
    cout << "\n";
    cout << list -> size();
    cout << "\n";
    list -> print();
    delete list;
    list = nullptr;
}