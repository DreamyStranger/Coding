#include <iostream>
#include "ListNode.h"

using namespace std;

/**
 * @brief Constructs a ListNode object.
 *
 * This constructor initializes the ListNode object with given value.
 * The value is set to 0 by default, and both the next and previous pointers are set to NULL.
 */
template <typename T>
ListNode<T>::ListNode(T x)
{
    value = x;
    next = nullptr;
    previous = nullptr;
}
