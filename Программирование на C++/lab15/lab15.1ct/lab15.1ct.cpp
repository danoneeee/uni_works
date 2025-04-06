#include <map>
#include <string>
#include <iostream>
using namespace std;

struct StudentGrade {
    string studentName;
    char grade;
};

void AddGrade(map<string, StudentGrade>& grades, const string& studentName, char grade) {
    grades[studentName] = { studentName, grade };
}

int main() {
    system("chcp 1251");
    map<string, StudentGrade> grades;
    AddGrade(grades, "Ivan", '1');
    AddGrade(grades, "Anna", '4');
    AddGrade(grades, "Maria", '5');
    AddGrade(grades, "Inna", '2');
    for (const auto& pair : grades) {
        cout << pair.first << ": " << pair.second.grade << endl;
    }

    string searchName;
    cout << "\nВведите имя для получения оценки ";
    cin >> searchName;

    auto it = grades.find(searchName);
    if (it != grades.end()) {
        cout << "Студент: " << it->first << ", Оценка: " << it->second.grade << endl;
    }
    else {
        cout << "Студент не найден." << endl;
    }

    string updateName;
    char newGrade;
    int ch;
    cout << "Хотите обновить оценку пользователя? (1 - да/ 2 - нет) \n";
    cin >> ch;
    if (ch == 1) {
        cout << "Введите имя студента для обновления оценки: ";
        cin >> updateName;
        cout << "Введите оценку студента: ";
        cin >> newGrade;
        grades[updateName].grade = newGrade;
        cout << "У студента " << updateName << " новая оценка " << grades[updateName].grade << endl;
    }
    else {
        return 0;
    }
    return 0;
}
