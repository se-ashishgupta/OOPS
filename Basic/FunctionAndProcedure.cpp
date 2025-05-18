#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

// Fucntion with no return value (procedure)
void printMessage()
{
    cout << "Hello, this is a procedure!" << endl;
}

int main()
{
    // function call
    int result = add(5, 10);
    cout << "Sum: " << result << endl;

    // procedure call
    printMessage();

    return 0;
}