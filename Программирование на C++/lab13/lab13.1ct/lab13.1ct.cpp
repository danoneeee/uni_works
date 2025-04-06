#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"
using namespace std;
int main()
{
    system("chcp 1251");
    char ch;
    string last_name, name, last_name_1;
    unsigned int teacher_work_time;
    const int MAX_PEOPLE = 100;
    human* people[MAX_PEOPLE];
    int count = 0;
    do
    {

        cout << "\nВводить данные для ученика или преподавателя(s / t) ? ";
        cin >> ch;
        if (ch == 't') {
            cout << "Фамилия : ";
            cin >> last_name;

            cout << "Имя : ";
            cin >> name;

            cout << "Отчество : ";
            cin >> last_name_1;

            cout << "Количество часов работы : ";
            cin >> teacher_work_time;

            people[count++] = new teacher(last_name, name, last_name_1, teacher_work_time);
        }
        else
        {
            vector<int> scores;
            cout << "Фамилия : ";
            cin >> last_name;

            cout << "Имя : ";
            cin >> name;

            cout << "Отчество : ";
            cin >> last_name_1;

            scores.push_back(5);
            scores.push_back(3);
            scores.push_back(4);

            people[count++] = new student(last_name, name, last_name_1, scores);
        }
        cout << "Продолжить ввод (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < count; ++i)
    {
        people[i]->GetInfo();
        cout << endl;
    }
    return 0;
}

