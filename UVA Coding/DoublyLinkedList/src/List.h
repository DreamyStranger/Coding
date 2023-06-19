#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

#include "ListNode.h"
#include "ListItr.h"

template <typename T>
class ListNode;

template <typename T>
class ListItr;

using namespace std;

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
    List<T>();

    /**
     * @brief Copy constructor.
     *
     * Creates a new list of ListNodes whose contents are the same values as the ListNodes in `source`.
     * @param source The source List to be copied.
     */
    List<T>(const List &source);

    /**
     * @brief Destructor.
     *
     * Empties the list and reclaims the memory allocated in the constructor for head and tail.
     */
    ~List<T>();

    /**
     * @brief Copy assignment operator.
     *
     * Assigns the contents of `rhs` to the current list.
     * @param rhs The right-hand-side List to be copied.
     * @return Reference to the current list.
     */
    List<T> &operator=(const List &source);

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
    ListNode<T> *head; // Dummy node representing the beginning of the list
    ListNode<T> *tail; // Dummy node representing the end of the list
    int count;         // Number of elements in the list
};

template <typename T>
List<T>::List()
{
    head = new ListNode<T>();
    tail = new ListNode<T>();
    head->next = tail;
    tail->previous = head;
    count = 0;
}

template <typename T>
List<T>::List(const List<T> &source)
{
    head = new ListNode<T>();
    tail = new ListNode<T>();
    head->next = tail;
    tail->previous = head;

    ListItr<T> iter(source.head->next);
    while (!iter.isPastEnd())
    {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
    count = source.count;
}

template <typename T>
List<T>::~List()
{
    makeEmpty();
    delete tail;
    delete head;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &source)
{
    if (this != &source)
    {
        makeEmpty();
        ListItr<T> position(source.head->next);
        while (!position.isPastEnd())
        {
            insertAtTail(position.retrieve());
            position.moveForward();
        }
        count = source.count;
    }
    return *this;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return head->next == tail;
}

template <typename T>
void List<T>::makeEmpty()
{
    while (!isEmpty())
    {

        ListItr<T> iter = first();

        (iter.current->previous)->next = iter.current->next;

        (iter.current->next)->previous = iter.current->previous;

        delete iter.current;
    }

    count = 0;
}

template <typename T>
ListItr<T> List<T>::first()
{
    return ListItr<T>(head->next);
}

template <typename T>
ListItr<T> List<T>::last()
{
    return ListItr<T>(tail->previous);
}

template <typename T>
void List<T>::insertAfter(T x, ListItr<T> position)
{
    if (position.isPastEnd())
    {
        throw std::invalid_argument("Cannot insert after the end of the list.");
    }

    ListNode<T> *newNode = new ListNode<T>(x);
    newNode->previous = position.current;
    newNode->next = position.current->next;
    newNode->next->previous = newNode;
    position.current->next = newNode;
    count++;
}

template <typename T>
void List<T>::insertBefore(T x, ListItr<T> position)
{
    if (position.isPastBeginning())
    {
        throw std::invalid_argument("Cannot insert before the beginning of the list.");
    }

    ListNode<T> *newNode = new ListNode<T>(x);
    newNode->next = position.current;
    newNode->previous = position.current->previous;
    newNode->previous->next = newNode;
    position.current->previous = newNode;
    count++;
}

template <typename T>
void List<T>::insertAtTail(T x)
{
    insertBefore(x, ListItr<T>(tail));
}

template <typename T>
ListItr<T> List<T>::find(T x)
{
    ListItr<T> iter = first();
    while (!iter.isPastEnd() && iter.retrieve() != x)
    {
        iter.moveForward();
    }
    return iter;
}

template <typename T>
void List<T>::remove(T x)
{
    ListItr<T> iter = find(x);
    if (!iter.isPastEnd())
    {
        iter.current->previous->next = iter.current->next;
        iter.current->next->previous = iter.current->previous;
        delete iter.current;
        count--;
    }
}

template <typename T>
int List<T>::size() const
{
    return count;
}

template <typename T>
void List<T>::print(bool forward)
{
    if (forward)
    {
        for (ListItr<T> itr = first(); !itr.isPastEnd(); itr.moveForward())
        {
            cout << itr.retrieve() << " ";
        }
    }
    else
    {
        for (ListItr<T> itr = last(); !itr.isPastBeginning(); itr.moveBackward())
        {
            cout << itr.retrieve() << " ";
        }
    }
    cout << endl;
}

#endif