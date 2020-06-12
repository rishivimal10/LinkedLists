#include "doubly-linked-list.h"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* curr = head_;
    Node* after;

    for (int i =0; i < size_; i++)
    {
        after = curr -> next;
        delete curr;
        curr = after;
    }
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if (size_ == 0)
        return true;
    else
        return false;
}

bool DoublyLinkedList::full() const
{
    if (size_ == CAPACITY)
        return true;
    else
        return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if (index < 0 || index >= size_){
        if (size_ > 0)
            return tail_ -> value;
        else
            return 0;
    }


    else if (index == 0){
        return head_ -> value;
    }

    else{
        struct Node* curr = head_;

        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr->value;
    }

}

unsigned int DoublyLinkedList::search(DataType value) const
{
    struct Node* curr = head_;

    for (int i = 0; i < size_; i++){
        if (curr -> value == value)
            return curr -> value;

        curr = curr->next;
    }

    return size_;
}

void DoublyLinkedList::print() const
{
    struct Node* curr = head_;

    for (int i = 0; i < size_; i++){
        cout << curr ->value << ", ";
        curr = curr->next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    if (index < 0 || index >= size_)
        return 0;

    else if (index == 0)
        return head_;

    else {
        struct Node* curr = head_;

        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (index < 0 || index > size_)
        return false;

    struct Node* newNode = new Node(value);

    if (size_ == 0){
        newNode ->next = nullptr;
        newNode ->prev = nullptr;
        head_ = newNode;
        tail_ = newNode;
    }

    else if (index == 0){

        newNode->prev = nullptr;
        newNode->next = head_;

        head_ ->prev = newNode;
        head_ = newNode;
    }

    else if (index == (size_)){
        newNode ->next = nullptr;

        Node* last_ = tail_;
        newNode ->prev = last_;
        last_ -> next = newNode;

        tail_ = newNode;
    }

    else {
        Node* before = getNode(index-1);
        Node* after = getNode(index);

        newNode ->prev = before;
        newNode -> next = after;

        before ->next = newNode;
        after->prev = newNode;
    }

    size_++;
    return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    struct Node* newNode = new Node(value);

    if (size_ == 0){
        newNode ->next = nullptr;
        newNode ->prev = nullptr;
        head_ = newNode;
        tail_ = newNode;
    }

    else{
        newNode->prev = nullptr;
        newNode->next = head_;

        head_ ->prev = newNode;
        head_ = newNode;
    }

    size_++;
    return true;

}

bool DoublyLinkedList::insert_back(DataType value)
{
    struct Node* newNode = new Node(value);

    if (size_ == 0){
        newNode ->next = nullptr;
        newNode ->prev = nullptr;
        head_ = newNode;
        tail_ = newNode;
    }

    else{
        newNode ->next = nullptr;

        Node* last_ = tail_;
        newNode ->prev = last_;
        last_ -> next = newNode;

        tail_ = newNode;
    }

    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (index < 0 || index >= size_|| size_== 0)
        return false;

    else if (index == 0){
        if (size_ == 1){
            head_ = nullptr;
            tail_ = nullptr;
        }

        else{
            Node* after = getNode(index+1);
            Node* curr = getNode(index);
            delete curr;
            after -> prev = nullptr;
            head_ = after;
        }

    }

    else if (index == (size_ -1)){
        Node* before = getNode(index-1);

        Node* curr = getNode(index);
        delete curr;

        before -> next = nullptr;
        tail_ = before;
    }

    else{
        Node* before = getNode(index-1);
        Node* after = getNode(index+1);

        Node* curr = getNode(index);
        delete curr;

        before -> next = after;
        after -> prev = before;
    }

    size_--;
    return true;

}

bool DoublyLinkedList::remove_front()
{
    if (size_ == 0){
        return false;
    }

    else{
        Node* after = getNode(1);
        after -> prev = nullptr;
        head_ = after;
        size_--;
        return true;
    }

}

bool DoublyLinkedList::remove_back()
{
    if (empty())
        return false;

    else{
        Node* before = getNode(size_-2);
        before -> next = nullptr;
        tail_ = before;
        size_--;
        return true;
    }

}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (index < 0 || index >= size_|| size_== 0)
        return false;

    else{
        Node* curr = getNode(index);
        curr -> value = value;
        return true;
    }

}

