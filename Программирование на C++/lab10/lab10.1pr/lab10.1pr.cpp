#include <iostream>
#include <string>
#include "student.h"
using namespace std;
int main()
{
    string name;
    string last_name;
    string cat;
    int id;
    cout << "Name: ";
    getline(cin, name);
    cout << "Last name: ";
    getline(cin, last_name);
    cout << "categ: ";
    getline(cin, cat);
    cout << "id: ";
    cin >> id;

    IdCard idc(id, cat);
    IdCard* idc_ptr = &idc;
    Student* student02 = new Student(name, last_name, idc_ptr);

    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;
    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
        // суммирование
        sum += scores[i];
    }
    // Сохраняем промежуточные оценки в объект класса Student
    student02->set_scores(scores);
    float average_score = sum / 5.0;
    // Сохраняем средний балл в объект класса Student
    student02->set_average_score(average_score);
    // Выводим данные по студенту
    cout << "Average ball for " << student02->get_name() << " "
        << student02->get_last_name() << " is "
        << student02->get_average_score() << endl;
    cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
    cout << "Category: " << student02->getIdCard().getCategory() << endl;
    delete student02;
    return 0;
}