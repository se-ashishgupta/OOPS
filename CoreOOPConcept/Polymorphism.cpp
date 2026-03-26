#include <iostream>
using namespace std;

// 🔹 What is Polymorphism?
// Polymorphism means:
// One name, many behaviors.
// In programming:
// The same function call behaves differently for different objects.
// Polymorphism is the ability of a single interface to represent multiple forms, where the correct behavior is selected at runtime based on object type.

// Runtime Pollymorphism
// Virtual functions allow a base class reference to call derived class methods at runtime, enabling polymorphism.
// Virtual functions make runtime polymorphism possible.

// ✅ Function Overriding(using virtual)
//     Child class provides its own implementation of parent function.class

class Shape
{
public:
    virtual double area() const
    {
        return 0;
    }

    virtual void display() const
    {
        cout << "This is shape." << endl;
    }

    // Virtual destructor (important for proper cleanup)
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // override area function
    double area() const override
    {
        return 3.141 * radius * radius;
    }

    void display() const override
    {
        cout << "This is a circle with radius: " << radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // Override area method
    double area() const override
    {
        return width * height;
    }
    void display() const override
    {
        std::cout << "This is a rectangle with width " << width << " and height "
                  << height << std::endl;
    }
};
// Polymorphic behavior
void printArea(const Shape &shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
    shape.display();
}

int main()
{

    Circle myCircle(5);
    Rectangle myRect(2, 5);
    myCircle.display();

    printArea(myCircle);
    printArea(myRect);

    return 0;
}