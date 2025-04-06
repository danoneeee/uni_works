#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void printuser(char* programName) {
    cout << "Использование: " << programName << " [-a|-m] <число_1> <число_2>" << endl;
    cout << "-a : сложение" << endl;
    cout << "-m : умножение" << endl;
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");

    if (argc != 4) {
        cout << "Неверное количество аргументов!" << endl;
        printuser(argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cout << "Второй аргумент должен быть '-a' или '-m'!" << endl;
        printuser(argv[0]);
        return 1;
    }

    int ch1 = atoi(argv[2]);
    int ch2 = atoi(argv[3]);

    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "Сумма: " << ch1 + ch2 << endl;
    }
    else if (strncmp(argv[1], "-m", 2) == 0) {
        cout << "Произведение: " << ch1 * ch2 << endl;
    }

    return 0;
}