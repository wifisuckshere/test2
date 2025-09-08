#include <iostream>
using namespace std;

class Shape {
private:
    string color;
public:
    virtual int calcArea() = 0;
    virtual Shape* clone() = 0;
    virtual void Identify() = 0;
};

class Square : public Shape {
private:
    string color;
    int sides;
public:
    int calcArea() { return sides * sides; }
    Shape* clone() { return new Square (*this); }
    Square() { cout << "Enter square color: "; cin >> color; cout << "Enter sides length: "; cin >> sides; }
    void Identify() { cout << endl << color << " square with area " << calcArea() << "."; }
};

class RATriangle : public Shape {
private:
    string color;
    int height;
    int width;
public:
    int calcArea() { return (height * width) / 2; }
    Shape* clone() { return new RATriangle(*this); }
    RATriangle() { cout << "Enter triangle color: "; cin >> color; cout << "Enter height: "; cin >> height; cout << "Enter width: "; cin >> width; }
    void Identify() { cout << endl << color << " triangle with area " << calcArea() << "."; }
};

int main()
{
    Shape* s = new Square;
    Shape* t = new RATriangle;

    Shape* s2 = s->clone();
    Shape* t2 = t->clone();

    s2->Identify();
    t2->Identify();
}