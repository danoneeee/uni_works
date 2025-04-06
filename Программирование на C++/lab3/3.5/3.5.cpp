#include <iostream>
#include <cmath>  

using namespace std;

int main() {
    system("chcp 1251");
    double number;  

    
    cout << "Введите число для вычисления его кубического корня: ";
    cin >> number;

 
    double cubic_root_pow = pow(number, 1.0 / 3.0);
    cout << "Кубический корень числа " << number << " (метод pow): " << cubic_root_pow << endl;
   

    double epsilon = 1e-6; 
    double guess = number / 3.0; 


    while (true) {
        double next_guess = (2.0 * guess + number / (guess * guess)) / 3.0;
        
        guess = next_guess; 
    }

    cout << "Кубический корень числа " << number << " (метод Ньютона): " << guess << endl;

    return 0; 
}