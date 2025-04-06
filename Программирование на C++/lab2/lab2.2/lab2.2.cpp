#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    system("chcp 1251");
    long in;
    string k, s;
    cout << "Введите снилс: ";
    cin >> in;

    k = to_string(in);
    k = k.substr(9, 2);
    in = in / 100;

    int x = 0;
    for (int i = 1; i < 10; i++) {
        int temp = in % 10 * i;
        x += temp;
        in = in / 10;
    }

    if (x < 100) {
        s = to_string(x);
    }
    else if (x == 100 || x == 101) {
        s = "00";
    }
    else if (x > 101) {
        if (x % 101 < 100) {
            s = to_string(x % 101);
        }
        else {
            s = "00";
        }
    }

    if (s == k) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}