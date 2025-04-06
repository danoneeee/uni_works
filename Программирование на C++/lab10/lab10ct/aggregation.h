#pragma once
#include "Dot.h"

class Aggregation {
private:
    Dot& a;
    Dot& b;
    Dot& c;

public:
    Aggregation(Dot& a, Dot& b, Dot& c);
    void printSides();
    double perimeter();
    double area();
};
