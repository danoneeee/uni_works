#include <iostream>
#include <string>
using namespace std;

int r_sum(int n) {
    if (n == 1) return 5;
    else return (5 * n + r_sum(n - 1));
}

int main() {
    system("chcp 1251");
    int n;
    cout << "Введите n" << endl;
    cin >> n;
    cout << r_sum(n) << endl;
    return 0;
}