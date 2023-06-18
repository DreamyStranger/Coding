#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

template <typename T>

/**
 * @class ListNode
 * @brief Represents a node in a linked list.
 *
 * The ListNode class provides a basic structure for a node in a linked list.
 * It stores a  value and pointers to the next and previous nodes in the list.
 */
class ListNode
{
public:
    /**
     * @brief Default constructor for ListNode.
     *
     * Constructs a ListNode object with given value.
     */
    ListNode(T x);

private:
    T value;          /**< The value of the node. */
    ListNode<T> *next;     /**< Pointer to the next ListNode in the list. */
    ListNode<T> *previous; /**< Pointer to the previous ListNode in the list. */

    friend class<T> List;    /**< List needs access to value, next, and previous. */
    friend class<T> ListItr; /**< ListItr needs access to value. */
};

#endif
