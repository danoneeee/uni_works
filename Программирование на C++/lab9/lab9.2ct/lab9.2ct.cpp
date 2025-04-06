#include <iostream>


using namespace std;
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    class ErrorT {
    public:
        string origin;
        int value;
        ErrorT(string orgn, int sc) {
            origin = orgn;
            value = sc;
        }
    };
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) {
        normalize(h, m, s);
    }


    void normalize(int h, int m, int s) {
        if (h < 0) {
            throw ErrorT(" error: hours < 0", h);
        }
        if (m < 0) {
            throw ErrorT(" error: minutes < 0", m);
        }
        if (s < 0) {
            throw ErrorT(" error: seconds < 0", s);
        }

        while (s >= 60) {
            s -= 60;
            ++m;
        }
        while (s < 0) {
            s += 60;
            --m;
        }

        while (m >= 60) {
            m -= 60;
            ++h;
        }
        while (m < 0) {
            m += 60;
            --h;
        }


        h %= 24;
        if (h < 0) {
            h += 24;
        }

        hours = h;
        minutes = m;
        seconds = s;
    }

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }

    void displayTime() const {
        cout << hours << ":"
            << minutes << ":"
            << seconds << endl;
    }

    Time add(const Time& other) const {
        int totalSeconds = toTotalSeconds() + other.toTotalSeconds();
        int newHours = totalSeconds / 3600;
        int remainingSeconds = totalSeconds % 3600;
        int newMinutes = remainingSeconds / 60;
        int newSeconds = remainingSeconds % 60;

        return Time(newHours, newMinutes, newSeconds);
    }

private:
    int toTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
};


int main() {


    try
    {
        Time t1(12, 58, 13);
        Time t2(11, 35, -78);

        cout << "Time t1: ";
        t1.displayTime();

        cout << "Time t2: ";
        t2.displayTime();

        Time sum = t1.add(t2);

        cout << "Summa t1 and t2: ";
        sum.displayTime();
    }
    catch (Time::ErrorT& er)
    {
        cout << "\nError: " << er.origin;
        cout << "\nInvalid value -> " << er.value;
    }
    return 0;
}