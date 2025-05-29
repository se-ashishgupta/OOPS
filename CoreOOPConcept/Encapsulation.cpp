#include <iostream>
using namespace std;

// Encapsulation is the bundling of data and methods that operate on that data within a single unit (the class). It also involves restricting direct access to some of the object's components, which is a means of preventing accidental modification of data.

// In C++, encapsulation is achieved using access specifiers:

// private: Members can only be accessed within the class
// protected: Members can be accessed within the class and by derived classes
// public: Members can be accessed from anywhere

class BankAccount
{
private:
    double balance;
    string accountNumber;

public:
    BankAccount(string accountNo, double initialBalance)
    {
        accountNumber = accountNo;
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
            accountNumber = accountNo;
            cout << "Initial balance cant be negative, Setting to 0" << endl;
        }
    }

    void deposite(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "New Balance is " << balance << endl;
        }
        else
        {
            cout << "Deposite amount cant be negative" << endl;
        }
    }
    void withdraw(double amount)
    {
        if (balance > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "New Balance is " << balance << endl;
        }
        else
        {
            cout << "insufficient  Balance" << endl;
        }
    }

    double getBalanace() const
    {
        return balance;
    }

    string getAccountNumber() const
    {
        return "XXXX" + accountNumber.substr(accountNumber.length() - 6);
    }
};

int main()
{

    BankAccount ashish("125478598745214", 5000);
    cout << ashish.getAccountNumber() << endl;
    ashish.deposite(50000);

    return 0;
}