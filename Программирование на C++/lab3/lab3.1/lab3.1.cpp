#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string checkSnils(string in) {
    string k, s;
    int perm;
   
    in.erase(remove(in.begin(), in.end(), ' '), in.end());
    in.erase(remove(in.begin(), in.end(), '-'), in.end());
    
    bool allDigits = in.find_first_not_of("0123456789") == string::npos;

    if (!allDigits) {
        cout << "Ошибка" << endl;
        return "False";
    }

    if (in.length() != 11)
    {
        cout << "Не содержит 11 цифр" << endl;
        return "False";
    }
    else {
        k = in.substr(9, 2);
        in = in.substr(0, 9);
        perm = atoi(in.c_str());
    }

    int x = 0;
    for (int i = 1; i < 10; i++) {
        int temp = perm % 10 * i;
        x += temp;
        perm = perm / 10;
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
        return "True";
    }
    else {
        return "False";
    }
}

int main() {
    system("chcp 1251");
    string in;

    cout << "Введите номер снилс: ";

    getline(cin, in);

    cout << checkSnils(in) << endl;

}