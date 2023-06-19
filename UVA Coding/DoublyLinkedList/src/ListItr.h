#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

template<typename T>
class List;

template<typename T>
class ListNode;

/**
 * @class ListItr
 * @brief Iterator class for traversing a linked list.
 *
 * The ListItr class provides functionality to traverse a linked list using an iterator.
 * It maintains a current position within the list and provides methods to move forward,
 * move backward, retrieve the value at the current position, and check if it's at the
 * beginning or end of the list.
 */
template <typename T>
class ListItr
{
public:
    /**
     * @brief Default constructor for ListItr.
     *
     * Constructs a ListItr object pointing to nullptr.
     */
    ListItr<T>();

    /**
     * @brief Constructor for ListItr with initial position.
     *
     * Constructs a ListItr object pointing to the given node.
     * @param theNode The node to set as the initial position.
     */
    ListItr<T>(ListNode<T> *theNode);

    /**
     * @brief Checks if the iterator is currently pointing past the end position in the list.
     *
     * @return True if the iterator is past the end position, false otherwise.
     */
    bool isPastEnd() const;

    /**
     * @brief Checks if the iterator is currently pointing past the beginning position in the list.
     *
     * @return True if the iterator is past the beginning position, false otherwise.
     */
    bool isPastBeginning() const;

    /**
     * @brief Advances the iterator to the next position in the list.
     *
     * Moves the iterator forward to the next position, unless it's already past the end of the list.
     */
    void moveForward();

    /**
     * @brief Moves the iterator back to the previous position in the list.
     *
     * Moves the iterator backward to the previous position, unless it's already past the beginning of the list.
     */
    void moveBackward();

    /**
     * @brief Retrieves the value at the current position of the list.
     *
     * @return The value at the current position.
     */
    T retrieve() const;

private:
    ListNode<T> *current; /**< Holds the position in the list. */

    friend class List<T>; /**< List class needs access to "current". */
};

template <typename T>
ListItr<T>::ListItr()
{
    current = nullptr;
}

template <typename T>
ListItr<T>::ListItr(ListNode<T> *theNode)
{
    current = theNode;
}

template <typename T>
bool ListItr<T>::isPastEnd() const
{
    return (current->next == nullptr);
}

template <typename T>
bool ListItr<T>::isPastBeginning() const
{
    return (current->previous == nullptr);
}

template <typename T>
void ListItr<T>::moveForward()
{
    if (current != nullptr && !isPastEnd())
    {
        current = current->next;
    }
}

template <typename T>
void ListItr<T>::moveBackward()
{
    if (current != nullptr && !isPastBeginning())
    {
        current = current->previous;
    }
}

template <typename T>
T ListItr<T>::retrieve() const
{
    if (current != nullptr)
    {
        return current->value;
    }
    else
    {
        throw std::runtime_error("Attempt to retrieve from a null pointer");
    }
}

#endif