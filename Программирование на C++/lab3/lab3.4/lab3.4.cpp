#include <iostream>
#include <string>
using namespace std;

void decimalToBinary(int num) {
    if (num > 0) {
        decimalToBinary(num / 2);
        cout << num % 2;
    }
}

int main() {
    system("chcp 1251");
    int num;
    cout << "Введите число:" << endl;
    cin >> num;
    decimalToBinary(num);
    return 0;
}