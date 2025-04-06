#include <iostream>
using namespace std;

template<typename T>
T calculateAverage(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    system("chcp 1251");
    int intArray[] = { 1, 2, 3, 4, 5 };
    int sred_1 = sizeof(intArray) / sizeof(intArray[0]);
    long longArray[] = { 10L, 20L, 30L, 40L, 50L };
    int sred_2 = sizeof(longArray) / sizeof(longArray[0]);
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int sred_3 = sizeof(doubleArray) / sizeof(doubleArray[0]);
    char charArray[] = { 'a', 'b', 'c', 'd' };
    int sred_4 = sizeof(charArray) / sizeof(charArray[0]) - 1;
    cout << "Среднее арифметическое для массива int: " << calculateAverage(intArray, sred_1) << endl;
    cout << "Среднее арифметическое для массива long: " << calculateAverage(longArray, sred_2) << endl;
    cout << "Среднее арифметическое для массива double: " << calculateAverage(doubleArray, sred_3) << endl;
    cout << "Среднее арифметическое для массива char: " << (int)calculateAverage(charArray, sred_4) << endl;
    return 0;
}