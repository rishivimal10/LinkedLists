#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType [cap];
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete [] data_;
    data_ = nullptr;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0)
        return true;

    else
        return false;
}

bool SequentialList::full() const
{
    if (size_ == capacity_)
        return true;

    else
        return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index < size_ && index >= 0){
            return data_[index];
    }

    else
        return data_[size_ - 1];
}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++)
    {
        if (val == data_[i])
            return i;
    }
    return size_;
}

void SequentialList::print() const
{
    for (int i = 0; i < size_; i++){
        std::cout << data_ [i];
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (full() || index < 0 || index > size_){
        return false;
    }

    if (index == size_){
        data_[index] = val;
        size_ += 1;
        return true;
    }
    else{
        for (int i = size_; i > index; i--){
            data_ [i] = data_[i - 1];
        }
        data_[index] = val;
        size_+= 1;
        return true;
    }
}

bool SequentialList::insert_front(DataType val)
{
    if (full())
        return false;

    if (empty()){
        data_[0] = val;
        size_+= 1;
        return true;
    }

    else{
        for (int i = size_; i > 0; i--){
            data_ [i] = data_[i - 1];
        }
        data_[0] = val;
        size_+= 1;
        return true;
    }
}

bool SequentialList::insert_back(DataType val)
{
    if (full())
        return false;

    else{
        data_[size_] = val;
        size_+= 1;
        return true;
    }
}

bool SequentialList::remove(unsigned int index)
{
    if (index < 0 || index >= size_){
        return false;
    }

    else{
        for (int i = index; i < (size_ -1); i++){
            data_[i] = data_ [i+1];
        }
        data_[size_ - 1] = NULL;
        size_ -=1;
        return true;
    }
}

bool SequentialList::remove_front()
{

    if (empty())
        return false;

    else{
        for (int i = 0; i < (size_ -1); i++){
            data_[i] = data_ [i+1];
        }
        data_[size_ - 1] = NULL;
        size_ -=1;
        return true;
    }
}

bool SequentialList::remove_back()
{
    if (empty())
        return false;

    else{
        data_[size_-1] = NULL;
        size_ -=1;
        return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index < 0 || index > size_){
        return false;
    }
    else{
        data_[index] = val;
        return true;
    }
}

