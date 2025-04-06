#include <iostream>

using namespace std;

bool transposition(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (i != 0) {
                swap(arr[i], arr[i - 1]);
            }
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    for (int i = 0; i < 4; i++) {
        cout << "Input key: ";
        cin >> key;

        bool found = transposition(arr, n, key);

        if (found) {
            cout << "Element founded." << endl;
        }
        else {
            cout << "Element not founded." << endl;
        }

        cout << "Changed array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

}