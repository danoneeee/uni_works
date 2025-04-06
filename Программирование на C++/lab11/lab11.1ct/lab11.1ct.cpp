#include <iostream>
using namespace std;

class Time {
public:
    class Error_input {
    public:
        int time;
        Error_input(int er) {
            time = er;
        }
    };
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) {
        check(h, m, s);
    }
    void check(int& h, int& m, int& s) {
        if (h < 0) {
            throw Error_input(h);
        }
        if (m < 0) {
            throw Error_input(m);
        }
        if (s < 0) {
            throw Error_input(s);
        }
        while (s >= 60) {
            s -= 60;
            ++m;
        }
        while (m >= 60) {
            m -= 60;
            ++h;
        }
        h %= 24;
        if (h < 0) {
            h += 24;
        }
        hours = h;
        minutes = m;
        seconds = s;
    }
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    void print() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time add(const Time& other) const {
        int totalSeconds = toTotalSeconds() + other.toTotalSeconds();
        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }

    int toTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
    Time from_seconds(int totalSeconds) const {
        totalSeconds = totalSeconds < 0 ? 0 : totalSeconds;
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    // Перегрузка оператора сложения двух объектов Time
    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }
    // Перегрузка оператора вычитания двух объектов Time
    Time operator-(const Time& other) const {
        int totalSeconds1 = toTotalSeconds();
        int totalSeconds2 = other.toTotalSeconds();
        int diffSeconds = totalSeconds1 - totalSeconds2;
        return from_seconds(diffSeconds);
    }
    // Перегрузка оператора сложения объекта Time и вещественного числа
    Time operator+(double seconds) const {
        return from_seconds(toTotalSeconds() + static_cast<int>(seconds));
    }
    // Перегрузка оператора сложения вещественного числа и объекта Time
    friend Time operator+(double seconds, const Time& time) {
        return time + seconds; // Используем уже реализованный метод
    }
    // Перегрузка оператора сравнения двух объектов Time
    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

private:

    int hours;
    int minutes;
    int seconds;
};

int main() {
    system("chcp 1251");
    try {
        const Time t1(8, 5, 5);
        const Time t2(2, 7, 5);
        t1.print(); 
        t2.print(); 
        Time t3 = t1 + t2;
        t3.print(); 
        Time t4 = t1 - t2;
        t4.print(); 
        Time t5 = t1 + 3661.5;
        t5.print(); 
        Time t6 = 120.5 + t2;
        t6.print(); 
        if (t1 == t2) {
            cout << "Время t1 и t2 одинаковое." << endl;
        }
        else {
            cout << "Время t1 и t2 разные." << endl;
        }
    }
    catch (const Time::Error_input& e) {
        cerr << e.time << endl;
        return 1;
    }
    return 0;
}