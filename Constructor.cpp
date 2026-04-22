#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
    double *salaryHistory;
    int historySize;

public:
    // Default Constructor
    Person() : name("unknown"), age(0), salaryHistory(nullptr), historySize(0)
    {
        cout << "Default Constructor is Initialized" << endl;
    }

    // Parametrized Constructor
    Person(string name, int age) : name(name), age(age), salaryHistory(0)
    {
        cout << "Parametrized Constructor Called" << endl;
        salaryHistory = new double[10];
        historySize = 10;
    }

    // Copy Constructor
    Person(const Person &other) : name(other.name), age(other.age), historySize(other.historySize)
    {
        cout << "Copy Constructor called" << endl;
        // Deep Copy
        if (other.salaryHistory != nullptr)
        {
            salaryHistory = new double[historySize];
            for (int i = 0; i < historySize; i++)
            {
                salaryHistory[i] = other.salaryHistory[i];
            }
        }
        else
        {
            salaryHistory = nullptr;
        }
    }

    // Move Constructor
    Person(Person &&other) noexcept : name(other.name), age(other.age), salaryHistory(other.salaryHistory), historySize(other.historySize)
    {
        cout << "Move Constructor called" << endl;
        // Transfer ownership and leave other in valid state
        other.salaryHistory = nullptr;
        other.historySize = 0;
    }

    ~Person()
    {
        cout << "Delete Constructor called" << endl;
        delete[] salaryHistory; // Free Aloocated History
    }

    void setSalary(int idx, double salary)
    {
        if (idx >= 0 && idx < historySize)
        {
            salaryHistory[idx] = salary;
        }
    }

    void display()
    {
        cout << "Name: " << name << " Age: " << age << endl;
    }
};

int main()
{
    Person p1;                 // Default
    Person p2("Ashish", 26);   // Parametrized
    Person p3(p2);             // Copy
    Person p4 = std::move(p3); // Move

    p4.display();

    return 0;
}