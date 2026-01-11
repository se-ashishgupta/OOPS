#include <iostream>
using namespace std;

class Vehical
{
protected:
    string brand;

public:
    Vehical(string b) : brand(b) {}

    void honk()
    {
        cout << "Beep Beep" << endl;
    }

    string getBrand() const
    {
        return brand;
    }
};

class Car : public Vehical
{
private:
    int numDoor;

public:
    Car(string b, int d) : Vehical(b), numDoor(d) {}

    void displayInfo()
    {
        cout << "Brand Name: " << brand << ", No of doors: " << numDoor << endl;
    }
};

class MotorCycle : public Vehical
{
private:
    bool numGear;

public:
    MotorCycle(string b, int n) : Vehical(b), numGear(n) {}

    void displayInfo()
    {
        cout << "Brand Name: " << brand << ", No of gears: " << numGear << endl;
    }
};

int main()
{

    Car car("BMW", 4);
    car.honk();
    car.displayInfo();

    MotorCycle motor("Harlay", 5);
    motor.honk();
    motor.displayInfo();

    return 0;
}