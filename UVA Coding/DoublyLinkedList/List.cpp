#include "List.h"

/**
 * @brief Default constructor that creates an empty list.
 *
 * Initializes the List object by setting up the basic list structure with the dummy head and tail nodes.
 */
template <typename T>
List<T>::List()
{
    head = new ListNode<T>(); // Dummy node representing the beginning of the list
    tail = new ListNode<T>(); // Dummy node representing the end of the list
    head->next = tail;
    tail->previous = head;
    count = 0;
}

/**
 * @brief Copy constructor.
 *
 * Constructs a new list by making a deep copy of the source list.
 * @param source The source List to be copied.
 */
template <typename T>
List<T>::List(const List<T> &source)
{
    makeEmpty();
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count = 0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd())
    {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

/**
 * @brief Destructor.
 *
 * Empties the list and deallocates memory allocated for the dummy head and tail nodes.
 */
template <typename T>
List<T>::~List()
{
    makeEmpty();
    delete tail;
    delete head;
}

/**
 * @brief Overloaded assignment operator for List.
 *
 * This operator is used to assign one List object to another. It performs a deep copy
 * of the given List object and manages memory to prevent leaks.
 *
 * @param rhs The List object to be copied.
 * @return A reference to the current List object after the copy has been made.
 */
template <typename T>
List<T> &List<T>::operator=(const List<T> &source)
{
    // Check for self-assignment
    if (this != &source)
    {
        // Clean up current list
        makeEmpty();

        // Iterate through the list to be copied
        ListItr position(source.head->next);
        while (!position.isPastEnd())
        {
            // Insert each item into the current list
            insertAtTail(position.retrieve());
            position.moveForward();
        }
        // Update the count
        count = source.count;
    }
    // Return the current object
    return *this;
}

/**
 * @brief Checks if the list is empty.
 *
 * @return True if the list is empty, false otherwise.
 */
template <typename T>
bool List<T>::isEmpty() const
{
    return head->next == tail;
}

/**
 * @brief Removes all items except the dummy head and tail nodes.
 *
 * The list should be a working empty list after this operation.
 */
template <typename T>
void List<T>::makeEmpty()
{
    if (!isEmpty())
    {
        ListItr position = first();
        while (!position.isPastEnd())
        {
            ListItr next = position;
            next.moveForward();
            delete position.current;
            position.current = nullptr;
            position = next;
        }
        head->next = tail;
        tail->previous = head;
        count = 0;
    }
}

/**
 * @brief Returns an iterator that points to the first ListNode after the dummy head node.
 *
 * @return ListItr object pointing to the first ListNode after the dummy head node.
 */
template <typename T>
ListItr<T> List<T>::first()
{
    return ListItr(head->next);
}

/**
 * @brief Returns an iterator that points to the last ListNode before the dummy tail node.
 *
 * @return ListItr object pointing to the last ListNode before the dummy tail node.
 */
template <typename T>
ListItr<T> List<T>::last()
{
    return ListItr(tail->previous);
}

/**
 * @brief Inserts a value after the current iterator position.
 *
 * @param x The value to be inserted.
 * @param position The ListItr object representing the current iterator position.
 */
template <typename T>
void List<T>::insertAfter(T x, ListItr<T> position)
{
    if (position.current == nullptr)
    {
        throw std::invalid_argument("Cannot insert before a null iterator position.");
    }

    ListNode *newNode = new ListNode(x);

    newNode->previous = position.current;
    newNode->next = position.current->next;
    newNode->next->previous = newNode;
    position.current->next = newNode;

    count++;
}

/**
 * @brief Inserts a value before the current iterator position.
 *
 * @param x The value to be inserted.
 * @param position The ListItr object representing the current iterator position.
 */
template <typename T>
void List<T>::insertBefore(T x, ListItr<T> position)
{
    if (position.current == nullptr)
    {
        throw std::invalid_argument("Cannot insert before a null iterator position.");
    }

    ListNode *newNode = new ListNode(x);

    newNode->next = position.current;
    newNode->previous = position.current->previous;
    newNode->previous->next = newNode;
    position.current->previous = newNode;

    count++;
}

/**
 * @brief Inserts a value at the tail of the list.
 *
 * @param x The value to be inserted.
 */
template <typename T>
void List<T>::insertAtTail(T x)
{
    insertAfter(x, last());
}

/**

    @brief Returns an iterator that points to the first occurrence of a value.
    If the value is not found in the list, it returns a ListItr object that points to the dummy tail node.
    @param x The value to search for.
    @return ListItr object pointing to the first occurrence of the value, or the dummy tail node if not found.
    */
template <typename T>
ListItr<T> List<T>::find(T x)
{
    ListItr iter = first();
    while (!iter.isPastEnd())
    {
        if (iter.retrieve() == x)
            return iter;
        iter.moveForward();
    }
    return iter;
}

/**

    @brief Removes the first occurrence of a value from the list.
    @param x The value to be removed.
    */
template <typename T>
void List<T>::remove(T x)
{
    ListItr iter = find(x);
    if (!iter.isPastEnd())
    {
        iter.current->previous->next = iter.current->next;
        iter.current->next->previous = iter.current->previous;
        delete iter.current;
        count--;
    }
}

/**

    @brief Returns the number of elements in the list.
    @return The number of elements in the list.
    */
template <typename T>
int List<T>::size() const
{
    return count;
}

/**

    @brief Prints the contents of the list forwards (head -> tail) or backwards (tail -> head).
    Prints the elements of the list in the specified order by using the ListItr class to iterate through the list.
    @param forward True to print forwards (head -> tail), false to print backwards (tail -> head).
    */
template <typename T>
void List<T>::print(bool forward)
{
    if (forward)
    {

        for (ListItr itr = first(); !itr.isPastEnd(); itr.moveForward())
        {
            cout << itr.retrieve() << " ";
        }
    }
    else
    {
        for (ListItr itr = last(); !itr.isPastBeginning(); itr.moveBackward())
        {
            cout << itr.retrieve() << " ";
        }
    }
    cout << endl;
}