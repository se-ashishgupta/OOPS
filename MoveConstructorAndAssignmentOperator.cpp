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

        cout << "Parameterized constructor called" << endl;
    }
    // Move Constructor
    MyString(MyString &&other) noexcept
    {
        length = other.length;
        data = other.data;

        // leave other in a valid state
        other.data = new char[1];
        other.data[0] = '\0';
        other.length = 0;

        cout << "Move constructor called" << endl;
    }

    // Copy Assignment operator
    MyString &operator=(MyString &&other) noexcept
    {
        if (this != &other) // Self assignment check
        {
            // free existing resources
            delete[] data;

            // Copy resource
            length = other.length;
            data = other.data;

            // leave other in a valid state
            other.data = new char[1];
            other.data[0] = '\0';
            other.length = 0;
        }

        cout << "Move assignment constructor called" << endl;
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
    MyString s2 = std::move(s1); // Move Constructor called
    MyString s3;
    s3 = std::move(s1); // Move assignment opertor called

    return 0;
}