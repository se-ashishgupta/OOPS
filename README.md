# OOP in C++ - Google Interview Preparation Guide

## Table of Contents

- [Core OOP Concepts](#core-oop-concepts)
  - [Classes and Objects](#classes-and-objects)
  - [Encapsulation](#encapsulation)
  - [Inheritance](#inheritance)
  - [Polymorphism](#polymorphism)
  - [Abstraction](#abstraction)
- [Advanced OOP Concepts](#advanced-oop-concepts)
  - [SOLID Principles](#solid-principles)
    - [Single Responsibility Principle](#single-responsibility-principle)
    - [Open/Closed Principle](#openclosed-principle)
    - [Liskov Substitution Principle](#liskov-substitution-principle)
    - [Interface Segregation Principle](#interface-segregation-principle)
    - [Dependency Inversion Principle](#dependency-inversion-principle)
  - [Design Patterns](#design-patterns)
    - [Singleton Pattern](#singleton-pattern)
    - [Factory Pattern](#factory-pattern)
    - [Observer Pattern](#observer-pattern)
  - [Memory Management](#memory-management)
    - [RAII](#resource-acquisition-is-initialization-raii)
    - [Smart Pointers](#smart-pointers)
  - [Multiple Inheritance](#multiple-inheritance-and-the-diamond-problem)
  - [Templates and Generic Programming](#templates-and-generic-programming)
- [Interview Tips](#interview-tips-for-oop-questions)

## Core OOP Concepts

### Classes and Objects

Classes are the blueprint for objects, which are instances of classes. In C++, they're defined with the `class` keyword:

```cpp
class Employee {
private:
    // Data members (attributes)
    std::string name;
    int id;
    double salary;

public:
    // Constructor
    Employee(std::string name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    // Methods
    void giveRaise(double percentage) {
        salary += salary * (percentage/100);
    }

    // Getters & Setters
    std::string getName() const { return name; }
    void setName(std::string newName) { name = newName; }
};
```

### Encapsulation

Encapsulation hides implementation details and exposes only necessary interfaces, achieved through access specifiers:

- `private`: Accessible only within the class
- `protected`: Accessible within the class and its derived classes
- `public`: Accessible from anywhere

```cpp
class BankAccount {
private:
    double balance; // Hidden implementation detail

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const { return balance; }
};
```

### Inheritance

Inheritance allows a class to inherit attributes and methods from another class:

```cpp
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(name), age(age) {}

    void introduce() const {
        std::cout << "Hi, I'm " << name << ", " << age << " years old." << std::endl;
    }
};

class Student : public Person {
private:
    std::string studentId;
    double gpa;

public:
    Student(std::string name, int age, std::string id, double gpa)
        : Person(name, age), studentId(id), gpa(gpa) {}

    void study() {
        std::cout << name << " is studying hard!" << std::endl;
    }

    // Method overriding
    void introduce() const {
        std::cout << "Hi, I'm student " << name << ", my ID is " << studentId << std::endl;
    }
};
```

### Polymorphism

Polymorphism allows objects to be treated as instances of their parent class while maintaining their derived behavior.

#### Runtime Polymorphism (using virtual functions)

```cpp
class Shape {
public:
    virtual double area() const {
        return 0;
    }

    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Polymorphic usage
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}
```

#### Compile-time Polymorphism (function overloading)

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

### Abstraction

Abstraction focuses on essential qualities rather than specifics, often implemented with abstract classes:

```cpp
class AbstractDatabase {
public:
    virtual void connect() = 0; // Pure virtual function
    virtual void disconnect() = 0;
    virtual bool execute(const std::string& query) = 0;
    virtual ~AbstractDatabase() {}
};

class MySQLDatabase : public AbstractDatabase {
public:
    void connect() override {
        // MySQL-specific connection code
    }

    void disconnect() override {
        // MySQL-specific disconnection code
    }

    bool execute(const std::string& query) override {
        // MySQL-specific execution code
        return true;
    }
};
```

## Advanced OOP Concepts

### SOLID Principles

#### Single Responsibility Principle

```cpp
// Bad: Class does too much
class ReportGenerator {
public:
    void generateReport(Data data) { /* ... */ }
    void saveToFile(std::string filename) { /* ... */ }
    void sendEmail(std::string recipient) { /* ... */ }
};

// Better: Separate responsibilities
class ReportGenerator {
public:
    Report generateReport(Data data) { /* ... */ }
};

class ReportSaver {
public:
    void saveToFile(const Report& report, std::string filename) { /* ... */ }
};

class EmailSender {
public:
    void sendEmail(const Report& report, std::string recipient) { /* ... */ }
};
```

#### Open/Closed Principle

```cpp
// Open for extension, closed for modification
class PaymentProcessor {
public:
    virtual bool processPayment(double amount) = 0;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        // Credit card processing logic
        return true;
    }
};

class PayPalProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        // PayPal processing logic
        return true;
    }
};

// Adding a new payment method doesn't modify existing code
class CryptocurrencyProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        // Cryptocurrency processing logic
        return true;
    }
};
```

#### Liskov Substitution Principle

```cpp
class Bird {
public:
    virtual void eat() { /* ... */ }
};

class FlyingBird : public Bird {
public:
    virtual void fly() { /* ... */ }
};

class Sparrow : public FlyingBird {
    // Sparrow can fly, so this inheritance is ok
};

class Penguin : public Bird {
    // Penguins can't fly, so we don't inherit from FlyingBird
};
```

#### Interface Segregation Principle

```cpp
// Bad: Forces classes to implement methods they don't need
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

// Better: Segregated interfaces
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Sleepable {
public:
    virtual void sleep() = 0;
};

class Human : public Workable, public Eatable, public Sleepable {
    // Implements all interfaces
};

class Robot : public Workable {
    // Only implements what it needs
};
```

#### Dependency Inversion Principle

```cpp
// High-level modules depend on abstractions, not concrete implementations
class EmailSender {
public:
    virtual void sendEmail(const std::string& to, const std::string& message) = 0;
};

class GMail : public EmailSender {
public:
    void sendEmail(const std::string& to, const std::string& message) override {
        // Gmail-specific implementation
    }
};

class Outlook : public EmailSender {
public:
    void sendEmail(const std::string& to, const std::string& message) override {
        // Outlook-specific implementation
    }
};

class NotificationService {
private:
    EmailSender& emailSender; // Depends on abstraction, not implementation

public:
    NotificationService(EmailSender& sender) : emailSender(sender) {}

    void notify(const std::string& user, const std::string& message) {
        emailSender.sendEmail(user, message);
    }
};
```

### Design Patterns

#### Singleton Pattern

```cpp
class DatabaseConnection {
private:
    // Private constructor prevents direct instantiation
    DatabaseConnection() {
        // Initialize connection
    }

    // Static instance
    static DatabaseConnection* instance;

public:
    // Delete copy constructor and assignment operator
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // Access point for singleton instance
    static DatabaseConnection& getInstance() {
        if (instance == nullptr) {
            instance = new DatabaseConnection();
        }
        return *instance;
    }

    void query(const std::string& sql) {
        // Execute query
    }
};

// Initialize static member
DatabaseConnection* DatabaseConnection::instance = nullptr;
```

#### Factory Pattern

```cpp
class Vehicle {
public:
    virtual void drive() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a car" << std::endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a truck" << std::endl;
    }
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(const std::string& type) {
        if (type == "car") {
            return new Car();
        } else if (type == "truck") {
            return new Truck();
        }
        return nullptr;
    }
};
```

#### Observer Pattern

```cpp
class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {}
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Remove observer from vector
    }

    void notifyObservers(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

class NewsAgency : public Subject {
private:
    std::string news;

public:
    void setNews(const std::string& newNews) {
        news = newNews;
        notifyObservers(news);
    }
};

class NewsChannel : public Observer {
private:
    std::string name;

public:
    NewsChannel(const std::string& channelName) : name(channelName) {}

    void update(const std::string& message) override {
        std::cout << name << " received news: " << message << std::endl;
    }
};
```

### Memory Management

#### Resource Acquisition Is Initialization (RAII)

```cpp
class FileHandler {
private:
    FILE* file;

public:
    FileHandler(const std::string& filename) {
        file = fopen(filename.c_str(), "r");
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandler() {
        if (file) {
            fclose(file);  // Resource automatically released when object is destroyed
        }
    }

    // Prevent copying to maintain RAII guarantees
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    // Read data from file
    std::string readLine() {
        // Implementation
        return "";
    }
};
```

#### Smart Pointers

```cpp
class Resource {
public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource released" << std::endl; }
    void use() { std::cout << "Resource being used" << std::endl; }
};

void useUniquePtr() {
    // Unique ownership - resource freed when ptr goes out of scope
    std::unique_ptr<Resource> ptr = std::make_unique<Resource>();
    ptr->use();

    // Transfer ownership - unique_ptr can't be copied
    std::unique_ptr<Resource> ptr2 = std::move(ptr);

    // ptr is now null, ptr2 owns the resource
    if (ptr2) ptr2->use();
}

void useSharedPtr() {
    // Shared ownership - resource freed when all ptrs go out of scope
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>();

    {
        std::shared_ptr<Resource> ptr2 = ptr1; // Reference count = 2
        ptr2->use();
    } // ptr2 destroyed, reference count = 1

    ptr1->use(); // Still valid
} // ptr1 destroyed, reference count = 0, resource freed

void useWeakPtr() {
    std::shared_ptr<Resource> shared = std::make_shared<Resource>();
    std::weak_ptr<Resource> weak = shared;

    // Check if resource still exists
    if (auto temp = weak.lock()) {
        temp->use();
    } else {
        std::cout << "Resource no longer available" << std::endl;
    }

    shared.reset(); // Resource destroyed

    // weak_ptr doesn't keep resource alive
    if (weak.expired()) {
        std::cout << "Resource has been destroyed" << std::endl;
    }
}
```

### Multiple Inheritance and the Diamond Problem

```cpp
class Device {
protected:
    std::string serialNumber;

public:
    Device(const std::string& serial) : serialNumber(serial) {}
    virtual void turnOn() = 0;
};

class Printer : public virtual Device {
public:
    Printer(const std::string& serial) : Device(serial) {}
    void turnOn() override { std::cout << "Printer on" << std::endl; }
    void print() { std::cout << "Printing" << std::endl; }
};

class Scanner : public virtual Device {
public:
    Scanner(const std::string& serial) : Device(serial) {}
    void turnOn() override { std::cout << "Scanner on" << std::endl; }
    void scan() { std::cout << "Scanning" << std::endl; }
};

// Without virtual inheritance, would have two copies of Device
class PrinterScanner : public Printer, public Scanner {
public:
    PrinterScanner(const std::string& serial)
        : Device(serial), Printer(serial), Scanner(serial) {}

    void turnOn() override {
        std::cout << "PrinterScanner on" << std::endl;
        // Or call specific parent implementations
        // Printer::turnOn();
        // Scanner::turnOn();
    }
};
```

### Templates and Generic Programming

```cpp
template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack underflow");
        }

        T top = elements.back();
        elements.pop_back();
        return top;
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

// Specialization for string type
template<>
class Stack<std::string> {
private:
    std::vector<std::string> elements;

public:
    void push(const std::string& item) {
        std::string copy = item;
        elements.push_back(std::move(copy));
    }

    std::string pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack underflow");
        }

        std::string top = std::move(elements.back());
        elements.pop_back();
        return top;
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    // String-specific method
    size_t totalLength() const {
        size_t total = 0;
        for (const auto& str : elements) {
            total += str.length();
        }
        return total;
    }
};
```

## Interview Tips for OOP Questions

1. **Focus on design decisions**: Explain why you chose certain patterns or principles.

2. **Consider trade-offs**: Discuss advantages and disadvantages of your design choices.

3. **Show SOLID understanding**: Demonstrate how your solution adheres to SOLID principles.

4. **Be prepared for extensions**: Interviewers often ask how you'd extend your solution for new requirements.

5. **Watch for edge cases**: Consider memory management, thread safety, and error handling.
