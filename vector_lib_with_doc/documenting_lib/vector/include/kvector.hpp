#ifndef KVECTOR_H
#define KVECTOR_H
/**
 * @file kvector.hpp
 * @brief  Declaration of the kvector class.
 * @class  kvector class 
 * /
class kvector : public list {
private:
    int *ptr;
   
    int capacity;

    
    int size;
  
    char allocationFlag
    bool addRow();

public:
    / **
     * @brief Default constructor.
     */
    kvector();

    /**
     * @brief Constructor with buffer size.
     * @param bufferSize The initial buffer size.
     */
    kvector(int bufferSize);

    /**
     * @brief Copy constructor.
     * @param other The other kvector object to copy from.
     */
    kvector(const kvector& other);

    /**
     * @brief Destructor.
     */
    virtual ~kvector();

    //---------------------------------------
    /**
     * @brief Assignment operator.
     * @param other The other kvector object to assign from.
     * @return Reference to the assigned kvector object.
     */
    kvector& operator=(const kvector& other);

    /**
     * @brief Compound assignment operator.
     * @param other The other kvector object to add.
     */
    void operator+=(const kvector& other);

    /**
     * @brief Addition operator.
     * @param other The other kvector object to add.
     * @return The resulting kvector after addition.
     */
    kvector operator+(const kvector& other);

    /**
     * @brief Subscript operator.
     * @param index The index to access.
     * @return Reference to the element at the specified index.
     */
    int & operator[](int index);
    //---------------------------------------

    /**
     * @brief Add a new element to the end of the array.
     * @param data The data to add.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    void add(int data, bool* success);

    /**
     * @brief Get the size of the array.
     * @return The size of the array.
     */
    int getSize() const;

    /**
     * @brief Get the element at the specified index.
     * @param index The index to access.
     * @param success Pointer to a boolean indicating if the operation was successful.
     * @return The element at the specified index.
     */
    int get(int index, bool* success) const;

    /**
     * @brief Insert an element at the specified index.
     * @param index The index to insert the element at.
     * @param data The data to insert.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    void insertAt(int index, int data, bool* success);

    /**
     * @brief Remove the element at the specified index.
     * @param index The index to remove the element from.
     * @param success Pointer to a boolean indicating if the operation was successful.
     * @return The removed element.
     */
    int removeAt(int index, bool* success);

    /**
     * @brief Update the element at the specified index.
     * @param index The index to update the element at.
     * @param data The new data value.
     * @param success Pointer to a boolean indicating if the operation was successful.
     */
    void update(int index, int data, bool* success);

    /**
     * @brief Remove all elements from the array.
     */
    void removeAll();

    /**
     * @brief Clear the array (remove all elements and reset size).
     */
    void clear();
};

#endif
