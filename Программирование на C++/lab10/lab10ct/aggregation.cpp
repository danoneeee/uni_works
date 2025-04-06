#include "aggregation.h"
#include <iostream>
#include <cmath>
#include "Dot.h"

Aggregation::Aggregation(Dot& a, Dot& b, Dot& c) : a(a), b(b), c(c) {}

void Aggregation::printSides() {
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ca = c.distanceTo(a);

    std::cout << "Стороны:" << std::endl;
    std::cout << "- AB: " << ab << std::endl;
    std::cout << "- BC: " << bc << std::endl;
    std::cout << "- CA: " << ca << std::endl;
}

double Aggregation::perimeter() {
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ca = c.distanceTo(a);

    return ab + bc + ca;
}

double Aggregation::area() {
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ca = c.distanceTo(a);

    double s = (ab + bc + ca) / 2;
    double area = sqrt(s * (s - ab) * (s - bc) * (s - ca));

    return area;
}