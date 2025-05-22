#include <iostream>
using namespace std;

class Employee
{
private:
    // Data members (characteristics)
    int id;
    string name;
    float salary;

public:
    // Constructor to initialize the Employee object
    Employee(int empId, string empName, float empSalary)
    {
        id = empId;
        name = empName;
        salary = empSalary;
    }

    // Method to display employee details
    void giveRaise(float percentage)
    {
        if (percentage > 0)
        {
            salary += salary * (percentage / 100);
            cout << "Salary after raise: " << salary << endl;
        }
        else
        {
            cout << "Invalid percentage" << endl;
        }
    }
    // Getter and Setter methods
    string getName()
    {
        return name;
    }
    void setName(string empName)
    {
        name = empName;
    }
};