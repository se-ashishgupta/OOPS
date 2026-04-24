#include <iostream>
using namespace std;

class ResourceManager
{
private:
    int *data;

public:
    ResourceManager()
    {
        data = new int[10];
        cout << "Constructor called" << endl;
    }

    ~ResourceManager()
    {
        delete[] data;
        cout << "Destructor called" << endl;
    }
};

int main()
{
    ResourceManager rm;
    return 0;
}