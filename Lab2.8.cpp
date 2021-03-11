#include <iostream>
#include "Triangle.h"
#pragma pack(1)

int main()
{
    cout << "Number of objects of class Triangle: " << Triangle::getCounter() << endl;
    Triangle first;
    cout << "Number of objects of class Triangle: " << Triangle::getCounter() << endl;
    cout << "Number of objects of class Angle: " << Triangle::Angle::getCounter() << endl;
    Triangle::Angle X;
    cout << "Number of objects of class Angle: " << Triangle::Angle::getCounter() << endl;

    cin >> first;

    cout << "\nAngle B to 360" << endl;
    cout << first.GetA().to360() << endl;

    cout << "\nAngle B to radians" << endl;
    cout << first.GetB().toRadian() << endl;

    cout << "\nAngle C get sin" << endl;
    cout << first.GetC().getSin() << endl;

    cout << "\nCompare angles A and B" << endl;
    first.GetC().Comparison(first.GetA(), first.GetB());

    cout << "\nFirst triangle" << endl;

    cout << first;

    cout << "\nSquare" << endl;
    cout << first.Square() << endl;

    cout << "\nAltitude A" << endl;
    cout << first.Altitude(1) << endl;

    cout << "\nPerimeter" << endl;
    cout << first.Perimeter() << endl;
    cout << "\nIncrease angle A" << endl;
    cin >> X;

    first.GetA().Increase(X, first.GetA(), first.GetB(), first.GetC(), 1);
    first.Equalizetriangle(1);

    cout << first;

    cout << "\nType of triangle" << endl;
    first.TypeOFTriangle();

    cout << "\nDecrease angle A" << endl;
    cin >> X;

    first.GetA().Decrease(X, first.GetA(), first.GetB(), first.GetC(), 1);
    first.Equalizetriangle(1);

    cout << first;

    cout << "\nType of triangle" << endl;
    first.TypeOFTriangle();

    cout << "\nA++" << endl;
    cout << first.GetA()++ << endl;

    cout << "\nA--" << endl;
    cout << first.GetA()-- << endl;

    cout << "\n++A" << endl;
    cout << ++first.GetA() << endl;

    cout << "\n--A" << endl;
    cout << --first.GetA() << endl;

    cout << "\n\nSize of class Triangel is equal to " << sizeof(Triangle) << endl;
    return 0;
}