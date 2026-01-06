#include <iostream>
using namespace std;

class Resource
{
private:
    int *data;

public:
    // Constructor
    Resource()
    {
        data = new int[10]; // Allocate memory for an array of 10 integers
        cout << "Resource acquired." << endl;
    }

    // Destructor
    ~Resource()
    {
        delete[] data; // Deallocate memory
        cout << "Resource released." << endl;
    }
};

void useResource()
{
    Resource res; // Resource is acquired here
    // Do something with the resource
} // Resource is released here when it goes out of scope

int main()
{
    cout << "Entering main function." << endl;
    useResource(); // Call the function that uses the resource
    cout << "Exiting main function." << endl;
    // Resource will be released automatically when the function scope ends
    return 0;
}