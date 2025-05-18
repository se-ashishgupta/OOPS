#include <iostream>
using namespace std;

// Pointer: A variable that stores the memory address of another variable.
// Reference: An alias for an existing variable.

int main()
{
    int a = 10; // Integer variable

    int *ptr = &a;                             // Pointer to the integer variable
    cout << "Pointer Value: " << *ptr << endl; // Dereferencing the pointer to get the value

    *ptr = 20;                                  // Changing the value using pointer
    cout << "New Integer Value: " << a << endl; // Output the new value of a

    int &ref = a;                               // Reference to the integer variable
    cout << "Reference Value: " << ref << endl; // Accessing the reference to get the value
    ref = 30;                                   // Changing the value using reference
    cout << "New Integer Value: " << a << endl; // Output the new value of a
    // Note: Pointers can be null, while references must always refer to a valid object.
    // Pointers can be reassigned to point to different variables, while references cannot be changed after initialization.
    // Pointers can be incremented or decremented, while references cannot be modified in this way.

    return 0;
}