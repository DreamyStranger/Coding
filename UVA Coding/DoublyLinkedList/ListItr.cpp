/**
 * @class ListItr
 * @brief Iterator class for traversing a linked list.
 *
 * The ListItr class provides functionality to traverse a linked list using an iterator.
 * It maintains a current position within the list and provides methods to move forward,
 * move backward, retrieve the value at the current position, and check if it's at the
 * beginning or end of the list.
 */

#include "ListItr.h"

/**
 * @brief Default constructor for ListItr.
 *
 * Constructs a ListItr object pointing to nullptr.
 */
template <typename T>
ListItr<T>::ListItr()
{
    current = nullptr;
}

/**
 * @brief Constructor for ListItr with initial position.
 *
 * Constructs a ListItr object pointing to the given node.
 * @param theNode The node to set as the initial position.
 */
template <typename T>
ListItr<T>::ListItr(ListNode<T> *theNode)
{
    current = theNode;
}

/**
 * @brief Checks if the iterator is currently pointing past the end position (dummy tail) in the list.
 *
 * @return True if the iterator is past the end position, false otherwise.
 */
template <typename T>
bool ListItr<T>::isPastEnd() const
{
    return (current->next == nullptr);
}

/**
 * @brief Checks if the iterator is currently pointing past the beginning position (dummy head) in the list.
 *
 * @return True if the iterator is past the beginning position, false otherwise.
 */
template <typename T>
bool ListItr<T>::isPastBeginning() const
{
    return (current->previous == nullptr);
}

/**
 * @brief Advances the iterator to the next position in the list.
 *
 * Moves the iterator forward to the next position, unless it's already past the end of the list.
 */
template <typename T>
void ListItr<T>::moveForward()
{
    if (!isPastEnd())
    {
        current = current->next;
    }
}

/**
 * @brief Moves the iterator back to the previous position in the list.
 *
 * Moves the iterator backward to the previous position, unless it's already past the beginning of the list.
 */
template <typename T>
void ListItr<T>::moveBackward()
{
    if (!isPastBeginning())
    {
        current = current->previous;
    }
}

/**
 * @brief Retrieves the value at the current position of the list.
 *
 * @return The value at the current position.
 */
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
