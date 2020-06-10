#ifndef A1_TESTS_HPP
#define A1_TESTS_HPP

#include "doubly-linked-list.h"
#include "sequential-list.h"
#include "polynomial.h"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class SequentialListTest
{
public:
    // New empty list is valid
    bool test1()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);

        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.capacity() == capacity)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        return true;
    }

    // insert_front() and insert_back() on zero-element list
    bool test2()
    {
        unsigned int capacity = 5;
        SequentialList list1(capacity);
        SequentialList list2(capacity);
        ASSERT_TRUE(list1.insert_front(100))
        ASSERT_TRUE(list2.insert_back(100))

        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.data_ != NULL)
        ASSERT_TRUE(list2.data_ != NULL)
        ASSERT_TRUE(list1.select(0) == list2.select(0) && list1.select(0) == 100)
        return true;
    }

    // select() and search() work properly
    bool test3()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }

        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
        ASSERT_TRUE(list.search(1000) == list.size())

        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.select(i) == i*100 && list.data_[i] == i*100)
        }
        return true;
    }

    // remove_front() and remove_back() on one-element list
    bool test4()
    {
        unsigned int capacity = 5;
        SequentialList list1(capacity);
        SequentialList list2(capacity);
        ASSERT_TRUE(list1.insert_front(100))
        ASSERT_TRUE(list2.insert_front(100))
        ASSERT_TRUE(list1.remove_front())
        ASSERT_TRUE(list2.remove_back())

        ASSERT_TRUE(list1.size_ == list2.size_ && list1.size_ == 0)
        ASSERT_TRUE(list1.empty() == true && list2.empty() == true)
        return true;
    }

    // Inserting too many elements should fail
    bool test5()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        // Fill up the list.
        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i))
        }

        // Try overfilling (they should all return false with no modifications).
        int val_not_inserted = 100;
        ASSERT_FALSE(list.insert_back(val_not_inserted))
        ASSERT_FALSE(list.insert_front(val_not_inserted))
        ASSERT_FALSE(list.insert(val_not_inserted, 3))

        // Check size is correct.
        ASSERT_TRUE(list.full() == true && list.empty() == false)
        ASSERT_TRUE(list.size_ == list.capacity_ && list.capacity_ == capacity)

        return true;
    }

    // insert_front() keeps moving elements forward
    bool test6()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);
        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_front(i))
            ASSERT_TRUE(list.size_ == (i + 1))
            for (int j = 0; j <= i; j++) {
                SequentialList::DataType expected_value = i - j;
                ASSERT_TRUE(list.data_[j] == expected_value)
            }
        }
        return true;
    }

    // inserting at different positions in the list succeeds
    bool test7()
    {
        unsigned int capacity = 10;
        SequentialList list(capacity);
        for (int i = 0; i < 4; i++) {
            ASSERT_TRUE(list.insert_back(i))
        }
        ASSERT_TRUE(list.insert(4, 1))
        ASSERT_TRUE(list.insert(5, 1))
        ASSERT_TRUE(list.insert(6, 5))
        ASSERT_TRUE(list.insert(7, 7))

        // Check that the list has the right values.
        int expected_values[] = {0, 5, 4, 1, 2, 6, 3, 7};
        ASSERT_TRUE(list.size_ == 8)
        for (int i = 0; i < list.size_; i++) {
            ASSERT_TRUE(list.data_[i] == expected_values[i])
        }

        return true;
    }

    // try to remove too many elements, then add a few elements
    bool test8()
    {
        unsigned int capacity = 5;
        const int num_elems = 4;
        SequentialList list(capacity);
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.insert_back(i))
        }
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.remove_back())
        }


        // Try a bunch of invalid commands.
        ASSERT_FALSE(list.remove_front())
        ASSERT_FALSE(list.remove_front())
        ASSERT_FALSE(list.remove(0))
        ASSERT_TRUE(list.empty() && list.size_ == 0)

        int expected_value = 1234;
        ASSERT_TRUE(list.insert(expected_value, 0))
        ASSERT_TRUE(list.data_[0] == expected_value)
        return true;
    }

    // lots of inserts and deletes, all of them valid
    bool test9()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);

        ASSERT_TRUE(list.insert_back(32))
        ASSERT_TRUE(list.insert_front(44))
        ASSERT_TRUE(list.insert(12,2))
        ASSERT_TRUE(list.remove_back())
        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.insert_back(88))
        ASSERT_TRUE(list.remove(1))
        ASSERT_TRUE(list.insert(99,0))

        // Check that the list has the right values
        ASSERT_TRUE(list.select(0) == 99 && list.data_[0] == 99)
        ASSERT_TRUE(list.select(1) == 32 && list.data_[1] == 32)

        return true;
    }

    // lots of inserts and deletes, some of them invalid
    bool test10()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);

        ASSERT_FALSE(list.remove(0))
        ASSERT_TRUE(list.insert_back(32))
        ASSERT_TRUE(list.insert_front(44))
        ASSERT_FALSE(list.insert(12,3))
        ASSERT_TRUE(list.insert(12,2))
        ASSERT_TRUE(list.remove_back())
        ASSERT_FALSE(list.remove(5))
        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.insert_back(88))
        ASSERT_FALSE(list.insert(12345,6))
        ASSERT_TRUE(list.remove(1))
        ASSERT_TRUE(list.insert(99,0))

        // Check that the list has the right values
        ASSERT_TRUE(list.select(0) == 99 && list.data_[0] == 99)
        ASSERT_TRUE(list.select(1) == 32 && list.data_[1] == 32)

        return true;
    }
};

#endif

