#include <iostream>
using namespace std;

class Box
{
private:
    double width;
    double height;
    double depth;

public:
    Box(double w, double h, double d) : width(w), height(h), depth(d) {}

    // Friend function declaration
    friend double calculateVolume(const Box &box);

    // friend class declaration
    friend class BoxManager;
};

// Friend function defination
double calculateVolume(const Box &box)
{
    return box.width * box.height * box.depth;
}

class BoxManager
{
public:
    void printBoxdimensions(const Box &box)
    {
        cout << "Width : " << box.width;
        cout << "Height : " << box.height;
        cout << "Depth : " << box.depth << endl;
    }

    void modifyBox(Box &box)
    {
        box.width *= 2;
        box.height *= 2;
        box.depth *= 2;
    }
};

int main()
{
    Box myBox(2, 3, 4);
    cout << "Volume : " << calculateVolume(myBox) << endl;

    BoxManager manager;
    manager.printBoxdimensions(myBox);
    manager.modifyBox(myBox);
    manager.printBoxdimensions(myBox);

    return 0;
}