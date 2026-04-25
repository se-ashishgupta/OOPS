#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int id;
    double salary;
    static int employeeCount;
    static double totalSalary;

public:
    Employee(string name, int id, double sal) : name(name), id(id), salary(sal)
    {
        employeeCount++;
        totalSalary += salary;
    }

    ~Employee()
    {
        employeeCount--;
        totalSalary -= salary;
    }

    static int getEmployeeCount()
    {
        return employeeCount;
    }

    static double getAverageSalary()
    {
        if (employeeCount > 0)
        {
            return totalSalary / employeeCount;
        }

        return 0;
    }

    void display()
    {
        cout << "ID: " << id << " Name: " << name << " Salary: " << salary << endl;
    }
};

// Initialize static data members
int Employee::employeeCount = 0;
double Employee::totalSalary = 0;

int main()
{
    cout << "Initial Employee Count: " << Employee::getEmployeeCount() << endl;

    {
        Employee e1("Ashish", 1, 50000);
        Employee e2("Ashish", 1, 50000);

        cout << "Current Employee Count: " << Employee::getEmployeeCount() << endl;
        cout << "Average Employee Salary: " << Employee::getAverageSalary() << endl;
    } // Scope end here e1 and e2 will be desstroye means destructor will be called

    cout << "Final Employee Count: " << Employee::getEmployeeCount() << endl;
    cout << "Final Average Employee Salary: " << Employee::getAverageSalary() << endl;
    return 0;
}