#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

Time InputTime() {
    Time t;
    cout << "\nHours: ";
    cin >> t.hours;
    cout << "Minutes: ";
    cin >> t.minutes;
    cout << "Seconds: ";
    cin >> t.seconds;

    return t;
}


Time AddTime(const Time& t1, const Time& t2)
{
    Time t;
    t.hours = t1.hours + t2.hours;
    t.minutes = t1.minutes + t2.minutes;
    t.seconds = t1.seconds + t2.seconds;

    if (t.seconds >= 60)
    {
        t.seconds -= 60;
        t.minutes++;
    }
    if (t.minutes >= 60)
    {
        t.minutes -= 60;
        t.hours++;
    }

    return t;
}

Time MinTime(const Time& t1, const Time& t2)
{
    Time t;
    t.hours = t1.hours - t2.hours;
    t.minutes = t1.minutes - t2.minutes;
    if (t.minutes >= 60)
    {
        t.minutes -= 60;
        t.hours--;
    }
    t.seconds = t1.seconds - t2.seconds;
    if (t.seconds < 0)
    {
        t.seconds += 60;
        t.minutes--;
    }

    return t;
}

void ShowTime(Time t)
{
    cout << t.hours << ":" << t.minutes << ":" << t.seconds << endl;
}


int main()
{
   
    Time t1 = InputTime();
    Time t2 = InputTime();

    Time add_t3 = AddTime(t1, t2);
    Time min_t4 = MinTime(t1, t2);

    ShowTime(t1);
    ShowTime(t2);
    ShowTime(add_t3);
    ShowTime(min_t4);

}
