#include <iostream>
using namespace std;

// Stack vs Heap Memory

// Stack: Automatic memory management, stores local variables and function calls.
//       - Memory is automatically allocated and deallocated
//       - Faster access
//       - Limited size
//       - Example: function call stack and local variables
//       - Memory is managed by the compiler

// Heap: Dynamic memory management, requires manual allocation and deallocation.
//       - Memory is allocated and deallocated using new and delete
//       - Slower access
//       - Larger size
//       - Example: dynamic arrays, linked lists
//       - Memory is managed by the programmer

int main()
{

    int stackVar = 10; // Stack variable automatically managed
    cout << "Stack Variable: " << stackVar << endl;

    int stackArray[5] = {1, 2, 3, 4, 5}; // Stack memory array automatically managed
    cout << "Stack Array: ";

    // Heap memory
    int *heapArray = new int[5]; // Dynamically allocated array on the heap

    delete[] heapArray; // Deallocate heap memory
    cout << "Heap Array Deallocated" << endl;
    // Note: Always remember to deallocate heap memory to avoid memory leaks
    // Memory leaks occur when dynamically allocated memory is not deallocated";

    return 0;
}