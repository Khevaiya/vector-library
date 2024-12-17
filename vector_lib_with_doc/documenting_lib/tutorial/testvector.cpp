/**
 * @example testvector.cpp
 * @author Khevaiya Ghode
 * @brief Example usage of the kvector class.
 */

#include <kvector.hpp> // Include the kvector header file
#include <iostream>

int main() {
    // Create a kvector object and perform various operations
    
    //-----add() & get() & parameterized constructor()-----------
    cout << " parameterized constructor & add() & get()" << endl;
    kvector k(20); // Create a kvector object with capacity 20
    bool succ;
    for (int e = 0; e <= 10; e++) {
        k.add(e, &succ); // Add elements to the kvector
    }
    for (int e = 0; e <= 10; e++) {
        cout << k.get(e, &succ) << endl; // Get elements from the kvector
    }
    
    //-----------------------------insertA()-------------
    cout << "insertAt()" << endl;
    bool success;
    cout << "size of kvector= " << k.getSize() << endl;
    k.insertAt(10, 20, &success); // Insert element at index 10
    for (int e = 0; e <= 11; e++) {
        cout << k.get(e, &success) << endl; // Get elements after insertion
    }
    cout << "size of kvector: " << k.getSize() << endl;
    
    //-----------------------------removeAt()----------------
    cout << "removeAt" << endl;
    k.removeAt(10, &success); // Remove element at index 10
    for (int e = 0; e <= 10; e++) {
        cout << k.get(e, &success) << endl; // Get elements after removal
    }
    cout << "size of kvector: " << k.getSize() << endl;
    
    //-----------------------------update()-------------------
    cout << "update()" << endl;
    k.update(10, 100, &succ); // Update element at index 10
    for (int e = 0; e <= 10; e++) {
        cout << k.get(e, &success) << endl; // Get elements after update
    }
    cout << "size of kvector: " << k.getSize() << endl;
    
    //------------------------------operator+ & operator=  -----------
    cout << " operator + and =" << endl;
    kvector i, j;
    i = j + k; // Perform addition of kvectors
    for (int e = 0; e <= 10; e++) {
        cout << i.get(e, &success) << endl; // Get elements after addition
    }
    cout << "size of kvector: " << k.getSize() << endl;
    
    //-------------------------------operator+=--------------------
    cout << "operaor+=" << endl;
    kvector l;
    l += i; // Perform compound addition
    for (int e = 0; e <= 10; e++) {
        cout << l.get(e, &success) << endl; // Get elements after compound addition
    }
    
    //-------------------------------copy constructor----------------
    cout << "copy constructor " << endl;
    kvector m(l); // Create a copy of l using copy constructor
    for (int e = 0; e <= 10; e++) {
        cout << m.get(e, &success) << endl; // Get elements of the copied vector
    }
    
    //--------------------operator[]---------------
    cout << "operator[]" << endl;
    m[0] = 1000; // Update element using subscript operator
    for (int e = 0; e <= 10; e++) {
        cout << m[e] << endl; // Access elements using subscript operator
    }
    
    //--------------------------removeAll()--------
    cout << "removeAll() or clear() against m object" << endl;
    m.removeAll(); // Remove all elements from m
    m.clear(); // Clear the kvector
    cout << m.getSize() << endl;
    for (int e = 0; e <= m.getSize(); e++) {
        cout << m[e] << endl; // Print elements after removal/clearing
    }
    
    //------------too test randomly----------
    kvector x;
    for (int e = 0; e <= 100; e++) {
        x.add(e, &succ); // Add elements to another kvector
    }
    cout << "-----------------------------" << endl;
    for (int e = 0; e < x.getSize(); e++) {
        cout << x.get(e, &succ) << endl; // Print elements of x
    }

    return 0;
}
