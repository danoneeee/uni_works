#pragma once
#include "Dot.h"

class TriangleComposition {
private:
    Dot a, b, c;

public:
    TriangleComposition(Dot a, Dot b, Dot c);
    void printSides();
    double perimeter();
    double area();
};
