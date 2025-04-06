#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("chcp 1251");
    int score = 0;
    int shots = 0;
    const int targetScore = 50;

    
    srand(time(0));

    double targetX = (double)rand() / RAND_MAX * 2 - 1;
    double targetY = (double)rand() / RAND_MAX * 2 - 1;

    while (score < targetScore) {
        double x, y;
        cout << "Введите координаты x и y: ";
        cin >> x >> y;

       
        double interferenceX = (double)rand() / RAND_MAX * 0.2 - 0.1;
        double interferenceY = (double)rand() / RAND_MAX * 0.2 - 0.1;
        x += interferenceX;
        y += interferenceY;

        double distance = sqrt(std::pow(x - targetX, 2) + pow(y - targetY, 2));

        if (distance <= 1) {
            score += 10;
        }
        else if (distance <= 2) {
            score += 5;
        }

        shots++;

        cout << "Текущий счет: " << score << endl;
    }

    cout << "Выстрелов сделано: " << shots << endl;

    if (score >= targetScore) {
        if (shots <= 5) {
            cout << "Уровень стрелка: Снайпер" << endl;
        }
        else if (shots <= 10) {
            cout << "Уровень стрелка: Просто стрелок" << endl;
        }
        else {
            cout << "Уровень стрелка: Новичок" << endl;
        }
    }

    return 0;
}