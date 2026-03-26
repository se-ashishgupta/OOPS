#include <iostream>
using namespace std;

// An abstract class in OOP is a class that cannot be instantiated directly and is meant to be inherited by other classes. It acts like a blueprint for derived classes.
// Think of it as:
// “I will define what methods must exist, but child classes will decide how they work.”ˀ
// If a class has = 0 after a virtual function → It is abstract.

// 🔹 What is Abstraction ?
// 👉 Definition : Abstraction means hiding internal implementation details and showing only what is necessary to the user.
// 👉 Real - life Example : When you use a car 🚗 You just use steering, brake, accelerator You don’t care how the engine works internally
// ➡️ That’s abstraction
// 🔹 Why Abstraction ? Reduces complexity Improves code readability Increases security(hides internal logic) Makes code easier to maintain
// 🔹 How Abstraction is Achieved in C++ ? 1️⃣ Abstract Class(Using Pure Virtual Function)
// 👉 A class becomes abstract when it has at least one pure virtual function
// 🔸 Syntax : class Shape
// {
// public:
//     virtual void draw() = 0; // pure virtual function
// };
// 👉 = 0 means : This function has no implementation here
//                    Child class must implement it
// 🔸 Example :
// #include <iostream>
//     using namespace std;

// // Abstract class
// class Shape
// {
// public:
//     // Pure virtual function
//     // Pure virtual function
//     virtual void draw() = 0;
// };

// // Derived class
// class Circle : public Shape
// {
// public:
//     void draw()
//     {
//         cout << "Drawing Circle" << endl;
//     }
// };

// // Derived class
// class Rectangle : public Shape
// {
// public:
//     void draw()
//     {
//         cout << "Drawing Rectangle" << endl;
//     }
// };

// int main()
// {
//     Shape *s1 = new Circle();
//     Shape *s2 = new Rectangle();

//     s1->draw(); // Calls Circle draw()
//     s2->draw(); // Calls Rectangle draw()
// }
// 🔹 Key Points : You cannot create objects of abstract class
//                 Shape s; ❌ (Not allowed)
// Used as a base class
// Forces child classes to implement behavior
// 🔹 2️⃣ Interface in C++
// 👉 In C++, there is no separate keyword for interface (like Java)
// 👉 But we create it like this:
// A class with only pure virtual functions
// No implementation at all
// 🔸 Example:
// class Animal
// {
// public:
//     virtual void sound() = 0;
//     virtual void eat() = 0;
// };
// 👉 This behaves like an interface
// 🔸 Implementation : class Dog : public Animal
// {
// public:
//     void sound()
//     {
//         cout << "Bark" << endl;
//     }

//     void eat()
//     {
//         cout << "Dog eats food" << endl;
//     }
// };
// 🔹 Abstract Class vs Interface
//             Feature Abstract Class Interface
//                 Functions Can have both normal +
//         pure virtual Only pure virtual Variables Allowed Allowed
//             Use Case Partial abstraction Full abstraction
// 🔹 Key Interview Insight 💡
// 👉 Abstraction focuses on :
// “What to do” instead of “How to do”
// 👉 Example : draw() → What to do Implementation inside Circle → How to do
// 🔹 When to Use
//     ? When you want to define a common structure
//       When multiple classes share behavior but implement differently
//       In large systems(like your agent orchestration project 👀)
// 🔹 Quick Summary
//       Abstraction = Hide complexity + show essentials
//                     Achieved via
//     : Abstract classes
//     Interfaces(pure abstract classes)
//         Uses pure virtual functions(= 0)
//             Cannot instantiate abstract class

class Shape
{
public:
    virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing rectangle" << endl;
    }
};

// Interface

class Animal
{
public:
    virtual void sound() = 0;
    virtual void eat() = 0;
};

class Dog
{
public:
    void sound()
    {
        cout << "Bho Bho" << endl;
    }

    void eat()
    {
        cout << "Padegry" << endl;
    }
};

class Goat
{
public:
    void sound()
    {
        cout << "Mee Mee" << endl;
    }

    void eat()
    {
        cout << "Grass" << endl;
    }
};

int main()
{
    Shape *shape1 = new Circle();
    Shape *shape2 = new Rectangle();

    shape1->draw();
    shape2->draw();

    return 0;
}

// Abstraction hides implementation details and shows only essential features.Encapsulation hides data and protects it using access modifiers.Polymorphism allows the same interface to behave differently based on the object.