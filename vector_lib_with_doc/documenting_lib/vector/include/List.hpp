#ifndef List__hpp
#define List__hpp 

/**
 * @file List.hpp
 * @brief Header file for the list abstract class.
 * @class List class
* /

#include <iostream>
class List {
public:
    / **
     * @brief Adds an element to the list.
     * @param data The data to add.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    virtual void add(int data, bool *success) = 0;

    /**
     * @brief Gets the size of the list.
     * @return The size of the list.
     */
    virtual int getSize() const = 0;

    /**
     * @brief Gets the element at the specified index.
     * @param index The index of the element to retrieve.
     * @param success Pointer to a boolean indicating if the operation was successful.
     * @return The element at the specified index, or -1 if index is out of bounds.
     */
    virtual int get(int index, bool *success) const = 0;

    /**
     * @brief Inserts an element at the specified index.
     * @param index The index at which to insert the element.
     * @param data The data to insert.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    virtual void insertAt(int index, int data, bool *success) = 0;

    /**
     * @brief Updates the element at the specified index.
     * @param index The index of the element to update.
     * @param data The new data to assign to the element.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    virtual void update(int index, int data, bool *success) = 0;

    /**
     * @brief Removes the element at the specified index.
     * @param index The index of the element to remove.
     * @param success Pointer to a boolean indicating if the operation was successful.
     * @return The data removed from the list, or -1 if index is out of bounds.
     */
    virtual int removeAt(int index, bool *success) = 0;

    /**
     * @brief Removes all elements from the list.
     */
    virtual void removeAll() = 0;

    /**
     * @brief Clears the list, deallocating memory and resetting size to zero.
     */
    virtual void clear() = 0;
};

#endif
//--------------------------------------
