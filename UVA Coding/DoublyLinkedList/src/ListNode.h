#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include "List.h"

template<typename T>
class List;
template<typename T>
class ListItr;

/**
 * @class ListNode
 * @brief Represents a node in a linked list.
 *
 * The ListNode class provides a basic structure for a node in a linked list.
 * It stores a  value and pointers to the next and previous nodes in the list.
 */
template <typename T>
class ListNode
{
public:
    /**
     * @brief Default constructor for ListNode.
     *
     * Constructs a ListNode object with given value.
     */
    ListNode(T x = T());

private:
    T value;               /**< The value of the node. */
    ListNode<T> *next;     /**< Pointer to the next ListNode in the list. */
    ListNode<T> *previous; /**< Pointer to the previous ListNode in the list. */

    friend class List<T>;    /**< List needs access to value, next, and previous. */
    friend class ListItr<T>; /**< ListItr needs access to value. */
};


template <typename T>
ListNode<T>::ListNode(T x)
{
    value = x;
    next = nullptr;
    previous = nullptr;
}

#endif
