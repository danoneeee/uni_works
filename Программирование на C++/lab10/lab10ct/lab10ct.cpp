#include <iostream>
#include "Dot.h"
#include "composition.h"
#include "aggregation.h"
using namespace std;
int main() {
    system("chcp 1251");
    // композиция
    Dot a1(0, 0);
    Dot b1(4, 0);
    Dot c1(0, 3);
    TriangleComposition triangleComp(a1, b1, c1);
    cout << "Композиция:" << endl;
    triangleComp.printSides();
    cout << "Периметр: " << triangleComp.perimeter() << endl;
    cout << "Площадь: " << triangleComp.area() << endl;

    // агрегация
    Dot a2(1, 1);
    Dot b2(5, 1);
    Dot c2(1, 4);
    Aggregation triangleAgre(a2, b2, c2);
    cout << "Агрегация:" << endl;
    triangleAgre.printSides();
    cout << "Периметр: " << triangleAgre.perimeter() << endl;
    cout << "Площадь: " << triangleAgre.area() << endl;
}