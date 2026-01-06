#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    int year;

public:
    Car(string b, string m, int y) : brand(b), model(m), year(y) {}

    void displayInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{

    // Creating objects of the Car class
    Car car1("Toyota", "Corolla", 2020);
    Car car2("Honda", "Civic", 2021);

    // Displaying information about the cars
    cout << "Car 1 Information:" << endl;
    car1.displayInfo();
    cout << endl;

    // Displaying information about the second car
    cout << "Car 2 Information:" << endl;
    car2.displayInfo();

    return 0;
}