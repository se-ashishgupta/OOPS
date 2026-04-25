#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload - operator for substraction
    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload + operator for addition
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload * operator for multiplication
    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overload == operator for equality comparison
    bool operator==(const Complex &other) const
    {
        return (real == other.real && imag == other.imag);
    }

    // Overload != operator for inequality comparison as this called already defined == operator
    bool operator!=(const Complex &other) const
    {
        return !(*this == other);
    }

    // Overload << operator for output stream
    // Why Friend? real and imag are private and this fucntion is outside the class
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real;
        if (c.imag >= 0)
        {
            os << " + " << c.imag << "i";
        }
        else
        {
            os << " - " << -c.imag << "i";
        }
        return os; // rteurn stream chainging works
    }

    // Overload << operator for input stream
    friend istream &operator>>(istream &is, Complex &c)
    {
        is >> c.real >> c.imag;
        return is;
    }

    // Overload prefix increment (++C) -> modify first then return updated object
    Complex &operator++()
    {
        ++real;
        return *this;
    }

    // Overload postfix increment (c++) -> return old value then update
    // int is dummy parameter which is used only to differentiate postfix from prefix

    Complex operator++(int)
    {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    // Overload assignment operator
    Complex &operator+=(const Complex &other)
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }
};

// friends allows access to pivate data
// return os/is enables chaining

int main()
{
    Complex c1(3, 2);
    Complex c2(1, 4);

    Complex c3 = c1 + c2; // Uses operator +
    cout << c3 << endl;   // Uses operator <<
    c1 += c2;             // Uses operator +=
    cout << c1 << endl;   // Uses operator <<
    Complex a = ++c1;     // Uses prefix operator
    cout << a << endl;    // Uses operator <<
    Complex b = c2++;     // Uses postfix operator
    cout << b << endl;    // Uses operator <<

    if (c1 == c2)
    {
        cout << "Both are equal" << endl;
    }
    else
    {
        cout << "Both are NOT equal" << endl;
    }

    return 0;
}