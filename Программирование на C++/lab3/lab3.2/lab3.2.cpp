#include <iostream>
#include <string>
using namespace std;

double sq(double x) {
    double res = sqrt(3) / 4;
    res = res * pow(x, 2);
    return res;
}

double sq(double x, double y, double z) {
    double p = (x + y + z) / 2;
    double res = sqrt(p * (p - x) * (p - y) * (p - z));
    return res;
}

int main() {
    system("chcp 1251");
    double a;
    cout << "Введите a" << endl;
    cin >> a;
    cout << sq(a) << endl;
    double x, y, z;
    cout << "Введите x, y, z" << endl;
    cin >> x >> y >> z;
    cout << sq(x, y, z) << endl;
  
}