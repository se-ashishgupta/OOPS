#include <iostream>
using namespace std;

class Base
{
private:
    int privateVar;      // Private member (characteristic), Accessible only within the class
    void privateMethod() // Private method (behavior), Accessible only within the class
    {
        cout << "Private method of Base class" << endl;
    }

protected:
    int protectedVar;      // Protected member (characteristic), Accessible within the class and derived
    void protectedMethod() // Protected method  (behavior), Accessible within the class and derived
    {
        cout << "Protected method of Base class" << endl;
    }

public:
    int publicVar;      // Public member (characteristic), Accessible from anywhere
    void publicMethod() // Public method    (behavior), Accessible from anywhere
    {
        cout << "Public method of Base class" << endl;
    }
};

class Derived : public Base
{
public:
    void accessBaseMembers()
    {
        // privateVar; // Error: Cannot access private member
        // privateMethod(); // Error: Cannot access private method

        protectedVar = 10; // Accessible
        protectedMethod(); // Accessible

        publicVar = 20; // Accessible
        publicMethod(); // Accessible
    }
};

int main()
{
    Base baseObj;
    Derived derivedObj;

    // baseObj.privateVar; // Error: Cannot access private member
    // baseObj.privateMethod(); // Error: Cannot access private method

    // baseObj.protectedVar; // Error: Cannot access protected member
    // baseObj.protectedMethod(); // Error: Cannot access protected method

    baseObj.publicVar = 30; // Accessible
    baseObj.publicMethod(); // Accessible

    derivedObj.accessBaseMembers(); // Accessing members from the derived class

    return 0;
}