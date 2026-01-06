#include <iostream>
using namespace std;

int main()
{

    // Primitives Data Types
    // C++ supports several built-in data types, including:
    int a = 10;                 // Integer
    float b = 20.5;             // Floating point
    char c = 'A';               // Character
    bool d = true;              // Boolean
    double e = 30.5;            // Double precision floating point
    string f = "Hello, World!"; // String

    // Output the values
    cout << "Integer: " << a << endl;
    cout << "Float: " << b << endl;
    cout << "Character: " << c << endl;
    cout << "Boolean: " << d << endl;
    cout << "Double: " << e << endl;
    cout << "String: " << f << endl;

    // Compound Data Types
    //  C++ also supports compound data types, such as:
    //  Arrays
    int arr[5] = {1, 2, 3, 4, 5}; // Array of integers
    cout << "Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Structures
    struct Person
    {
        string name;
        int age;
    };
    Person p;
    p.name = "John Doe";
    p.age = 30;
    cout << "Person Name: " << p.name << endl;
    cout << "Person Age: " << p.age << endl;
    Person p1 = {"Jane Doe", 25}; // Initializing structure
    cout << "Person 1 Name: " << p1.name << endl;
    cout << "Person 1 Age: " << p1.age << endl;

    // Unions
    union Data
    {
        int intValue;
        float floatValue;
        char charValue;
    };

    Data data;
    data.intValue = 10;
    cout << "Union Integer Value: " << data.intValue << endl;
    data.floatValue = 20.5;
    cout << "Union Float Value: " << data.floatValue << endl;
    data.charValue = 'A';
    cout << "Union Character Value: " << data.charValue << endl;

    // Difference between Structure and Union------------
    //  Structures allocate separate memory locations for each member, while unions share the same memory location for all members.

    // Enumerations
    enum Color
    {
        RED,
        GREEN,
        BLUE
    };
    Color myColor = GREEN;
    cout << "Enum Color Value: " << myColor << endl;

    // Pointers
    int *ptr = &a;                             // Pointer to an integer
    cout << "Pointer Value: " << *ptr << endl; // Dereferencing the pointer
    *ptr = 20;                                 // Changing the value using pointer
    cout << "New Integer Value: " << a << endl;

    // References
    int &ref = a;                               // Reference to an integer
    cout << "Reference Value: " << ref << endl; // Accessing the reference
    ref = 30;                                   // Changing the value using reference
    cout << "New Integer Value: " << a << endl;

    // Type Casting
    float g = 10.5;
    int h = (int)g; // Explicit type casting
    cout << "Type Casted Integer Value: " << h << endl;

    // const
    const int i = 100; // Constant integer
    // i = 200; // Error: cannot modify a const variable

    // volatile
    volatile int j = 200; // Volatile integer
    cout << "Volatile Integer Value: " << j << endl;
    // j = 300; // Can modify a volatile variable

    // sizeof
    cout << "Size of Integer: " << sizeof(a) << " bytes" << endl;
    cout << "Size of Float: " << sizeof(b) << " bytes" << endl;
    cout << "Size of Character: " << sizeof(c) << " bytes" << endl;
    cout << "Size of Boolean: " << sizeof(d) << " bytes" << endl;
    cout << "Size of Double: " << sizeof(e) << " bytes" << endl;
    cout << "Size of String: " << sizeof(f) << " bytes" << endl;
    cout << "Size of Array: " << sizeof(arr) << " bytes" << endl;
    cout << "Size of Structure: " << sizeof(p) << " bytes" << endl;
    cout << "Size of Union: " << sizeof(data) << " bytes" << endl;
    cout << "Size of Enumeration: " << sizeof(myColor) << " bytes" << endl;
    cout << "Size of Pointer: " << sizeof(ptr) << " bytes" << endl;
    cout << "Size of Reference: " << sizeof(ref) << " bytes" << endl;
    cout << "Size of Constant: " << sizeof(i) << " bytes" << endl;
    cout << "Size of Volatile: " << sizeof(j) << " bytes" << endl;

    // Type Modifiers
    signed int k = -10;  // Signed integer
    unsigned int l = 20; // Unsigned integer
    cout << "Signed Integer: " << k << endl;
    cout << "Unsigned Integer: " << l << endl;
    // long and short
    long m = 1000000; // Long integer
    short n = 10;     // Short integer
    cout << "Long Integer: " << m << endl;
    cout << "Short Integer: " << n << endl;

    // Type Aliases
    typedef unsigned long ulong; // Type alias for unsigned long
    ulong o = 1000000;           // Using the type alias
    cout << "Type Alias Unsigned Long: " << o << endl;
    using byte = unsigned char; // Type alias for unsigned char
    byte pByte = 255;           // Using the type alias
    cout << "Type Alias Unsigned Char: " << (int)pByte << endl;
    // nullptr
    int *nullPtr = nullptr; // Null pointer
    cout << "Null Pointer Value: " << nullPtr << endl;
    // nullptr_t
    // nullptr_t is a type that can hold a null pointer value
    // It is used to indicate that a pointer does not point to any object or function
    // nullptr_t is not a built-in type, but rather a type defined in the C++ standard library
    // It is used to provide a type-safe way to represent null pointers
    // nullptr_t is not a type that can be used directly, but rather a type that can be used to create null pointers
    // It is used to provide a type-safe way to represent null pointers

    return 0;
}