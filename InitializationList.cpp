#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;
    const double MAX_WIDTH;

public:
    // using Intialization list
    Rectangle(double w, double h) : width(w), height(h), MAX_WIDTH(100)
    {
        cout << "Consturcture called" << endl;
        // Constructor Body
        if (width > MAX_WIDTH)
        {
            width = MAX_WIDTH;
        }
    }
};

int main()
{
    Rectangle rec(10, 10);

    return 0;
}