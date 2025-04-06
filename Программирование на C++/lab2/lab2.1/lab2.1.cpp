#include <iostream>
#include <set>
using namespace std;


int main() {
    int n;
    cout << "Input num: "; 
    cin >> n;
    set<int> primes;
    primes.insert(2);


    if (n == 2) {
        cout << "Prime" << endl;

    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
            if (j == i - 1) {
                primes.insert(i);
            }
        }
        if (n % i == 0) {
            cout << "Not Prime" << endl;
            break;
        }
        if (i == n - 1) {
            if (find(primes.begin(), primes.end(), primes.size() + 1) != primes.end()) {
                cout << "Super Prime" << endl;
            }
            else {
                cout << "Prime" << endl;
            }
        }
    }
}