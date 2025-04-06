#include <iostream>
#include <cmath>

using namespace std;

int Myroot(double, double, double, double&, double&);


int main()
{
    double a = 2, b = 3, c = 1, x1, x2;

    Myroot(a, b, c, x1, x2);
}

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    double D = b * b - 4 * a * c;
    if (D > 0)

    {
        x1 = (-b + sqrt(D)) / 2 * a;
        x2 = (-b - sqrt(D)) / 2 * a;
        cout << "Two roots: x1 = " << x1 << "; x2 = " << x2;
    }

    if (D == 0)
    {
        x1 = -b / 2 * a;
        cout << "One root x1 = x2 = " << x1;

    }

    if (D < 0)
    {
        cout << "No roots";

    }
    return 0;
}