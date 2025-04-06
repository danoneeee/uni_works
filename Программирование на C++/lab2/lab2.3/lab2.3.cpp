#include <iostream>
using namespace std;

int main() {
    system("chcp 1251");
    int s;

    cout << "Введите сумму = "; cin >> s;

    int out = s / 10;
    out += (s % 10) / 5;
    out += ((s % 10) % 5) / 2;
    out += ((s % 10) % 5) % 2;

    cout << "Количество монет = " << out << endl;
}