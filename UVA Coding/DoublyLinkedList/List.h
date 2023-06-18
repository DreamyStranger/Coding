#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

template <typename T>
class ListItr; // Forward declaration of ListItr class

/**
 * @class List
 * @brief Doubly linked list class.
 *
 * The List class represents a doubly linked list with a dummy head and tail.
 * It provides various operations for manipulating and accessing the elements in the list.
 */
template <typename T>
class List
{
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the List object by setting up the basic list structure with the dummy head and tail nodes.
     */
    List();

    /**
     * @brief Copy constructor.
     *
     * Creates a new list of ListNodes whose contents are the same values as the ListNodes in `source`.
     * @param source The source List to be copied.
     */
    List(const List &source);

    /**
     * @brief Destructor.
     *
     * Empties the list and reclaims the memory allocated in the constructor for head and tail.
     */
    ~List();

    /**
     * @brief Copy assignment operator.
     *
     * Assigns the contents of `rhs` to the current list.
     * @param rhs The right-hand-side List to be copied.
     * @return Reference to the current list.
     */
    List &operator=(const List &source);

    /**
     * @brief Checks if the list is empty.
     *
     * @return True if the list is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Removes all items except the dummy head and tail nodes.
     *
     * The list should be a working empty list after this operation.
     */
    void makeEmpty();

    /**
     * @brief Returns an iterator that points to the first ListNode after the dummy head node.
     *
     * @return ListItr object pointing to the first ListNode after the dummy head node.
     */
    ListItr<T> first();

    /**
     * @brief Returns an iterator that points to the last ListNode before the dummy tail node.
     *
     * @return ListItr object pointing to the last ListNode before the dummy tail node.
     */
    ListItr<T> last();

    /**
     * @brief Inserts a value after the current iterator position.
     *
     * @param x The value to be inserted.
     * @param position The ListItr object representing the current iterator position.
     */
    void insertAfter(T x, ListItr<T> position);

    /**
     * @brief Inserts a value before the current iterator position.
     *
     * @param x The value to be inserted.
     * @param position The ListItr object representing the current iterator position.
     */
    void insertBefore(T x, ListItr<T> position);

    /**
     * @brief Inserts a value at the tail of the list.
     *
     * @param x The value to be inserted.
     */
    void insertAtTail(T x);

    /**
     * @brief Returns an iterator that points to the first occurrence of a value.
     *
     * If the value is not found in the list, it returns a ListItr object that points to the dummy tail node.
     * @param x The value to search for.
     * @return ListItr object pointing to the first occurrence of the value, or the dummy tail node if not found.
     */
    ListItr<T> find(T x);

    /**
     * @brief Removes the first occurrence of a value from the list.
     *
     * @param x The value to be removed.
     */
    void remove(T x);

    /**
     * @brief Returns the number of elements in the list.
     *
     * @return The number of elements in the list.
     */
    int size() const;

    /**
    @brief Prints the contents of the list forwards (head -> tail) or backwards (tail -> head).
    This function uses the ListItr class to iterate through the list and prints the values in the specified order.
    @param source The List to be printed.
    @param forward True to print forwards (head -> tail), false to print backwards (tail -> head).
    */
    void print(bool forward);

private:
    ListNode *head; // Dummy node representing the beginning of the list
    ListNode *tail; // Dummy node representing the end of the list
    int count;      // Number of elements in the list
};

#endif