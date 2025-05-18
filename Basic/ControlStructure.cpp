#include <iostream>
using namespace std;

int main()
{
    // Conditional Statements-----------------------
    // if-else statement
    int a = 10;
    if (a > 0)
    {
        cout << "a is positive" << endl;
    }
    else
    {
        cout << "a is negative or zero" << endl;
    }

    // switch statement
    switch (a)
    {
    case 1:
        cout << "a is 1" << endl;
        break;
    case 10:
        cout << "a is 10" << endl;
        break;
    default:
        cout << "a is neither 1 nor 10" << endl;
    }

    // Looping Statements--------------------------
    // for loop
    for (int i = 0; i < 5; i++)
    {
        cout << "for loop iteration: " << i << endl;
    }

    // while loop
    int j = 0;
    while (j < 5)
    {
        cout << "while loop iteration: " << j << endl;
        j++;
    }

    // do-while loop
    int k = 0;
    do
    {
        cout << "do-while loop iteration: " << k << endl;
        k++;
    } while (k < 5);

    // Break and Continue Statements -----------------
    // break statement
    for (int l = 0; l < 10; l++)
    {
        if (l == 5)
        {
            cout << "Breaking the loop at l = " << l << endl;
            break; // Break out of the loop
        }
        cout << "Loop iteration: " << l << endl;
    }

    // continue statement
    for (int m = 0; m < 10; m++)
    {
        if (m % 2 == 0)
        {
            cout << "Skipping even number: " << m << endl;
            continue; // Skip the rest of the loop for even numbers
        }
        cout << "Odd number: " << m << endl;
    }

    return 0;
}