#include <iostream>
using namespace std;

class BankAccount
{
private:
    float balance;

public:
    BankAccount(float initialBalance)
    {
        balance = initialBalance;
    }

    void deposit(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
            cout << "New balance: " << balance << endl;
        }
    }

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
};

int main()
{

    BankAccount account(1000.0); // Create a BankAccount object with an initial balance
    account.deposit(500.0);      // Deposit money
    account.withdraw(200.0);     // Withdraw money
    return 0;
}