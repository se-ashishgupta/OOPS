#include <iostream>
using namespace std;

// Global data
float balance = 1000.0;

// Function to deposite money
void deposite(float amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
}

// Function to withdraw money
void withdraw(float amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
    else
    {
        cout << "Insufficient funds" << endl;
    }
}

int main()
{
    deposite(500.0);
    withdraw(200.0);
    return 0;
}