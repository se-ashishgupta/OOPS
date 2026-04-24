#include <iostream>
using namespace std;

class MyString
{
private:
    char *data;
    size_t length;

public:
    // Constructor
    MyString(const char *str = nullptr)
    {
        if (str == nullptr)
        {
            data = new char[1];
            data[0] = '\0';
            length = 1;
        }
        else
        {
            length = strlen(str);
            data = new char[length];
            strcpy(data, str);
        }
    }
    // Copy Constructor
    MyString(const MyString &other)
    {
        length = other.length;
        data = new char[length];
        strcpy(data, other.data);
        cout << "Copy constructor called" << endl;
    }

    // Copy Assignment operator
    MyString &operator=(const MyString &other)
    {
        if (this != &other) // Self assignment check
        {
            // free existing resources
            delete[] data;

            // Copy resource
            length = other.length;
            data = new char[length];
            strcpy(data, other.data);
        }

        cout << "Copy assignment constructor called" << endl;
        return *this;
    }

    ~MyString()
    {
        delete[] data;
        cout << "Destructor called" << endl;
    }

    // Utility method
    void display() const
    {
        cout << data << endl;
    }
};

int main()
{
    MyString s1("hello");
    MyString s2 = s1; // Copy Constructor
    MyString s3;
    s3 = s1; // Copy assignment opertor called

    return 0;
}