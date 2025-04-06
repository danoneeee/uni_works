#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;
using Solution = tuple<double, double, bool>;

Solution solve(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D > 0) 
    {
        double x1 = (-b + sqrt(D)) / 2 * a;
        double x2 = (-b - sqrt(D)) / 2 * a;
        return make_tuple(x1, x2, true);
    }
    else if (D == 0) 
    {
        double root = -b / 2 * a;
        return make_tuple(root, root, true);
    }
    else 
    {
        return make_tuple(NAN, NAN, false);
    }
}

void printTupleOfThree(Solution t) {
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << get<2>(t) << ")" << endl;
}
int main() {
    double a, b, c;
    cout << "input a: " << endl;
    cin >> a;
    cout << "input b: " << endl;
    cin >> b;
    cout << "input c: ";
    cin >> c;
    auto solution = solve(a, b, c);
    printTupleOfThree(solution);
    return 0;
}