#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    int age;
    string phoneNumber;
public:
    Person(const string& firstName, const string& lastName, int age, const string& phoneNumber)
        : firstName(firstName), lastName(lastName), age(age), phoneNumber(phoneNumber) {}

    virtual void printInfo() const = 0;

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << person.firstName << " " << person.lastName << ", Age: " << person.age << ", Phone: " << person.phoneNumber;
        return os;
    }
};

class Student : public Person {
private:
    string university;
    string faculty;
public:
    Student(const string& firstName, const string& lastName, int age, const string& phoneNumber,
        const string& university, const string& faculty)
        : Person(firstName, lastName, age, phoneNumber),
        university(university),
        faculty(faculty) {}

    void printInfo() const override {
        cout << *this << ", University: " << university << ", Faculty: " << faculty << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
public:
    Teacher(const string& firstName, const string& lastName, int age, const string& phoneNumber,
        const string& subject)
        : Person(firstName, lastName, age, phoneNumber),
        subject(subject) {}

    void printInfo() const override {
        cout << *this << ", Subject: " << subject << endl;
    }
};

class Colleague : public Person {
private:
    string company;
    string position;
public:
    Colleague(const string& firstName, const string& lastName, int age, const string& phoneNumber,
        const string& company, const string& position)
        : Person(firstName, lastName, age, phoneNumber),
        company(company),
        position(position) {}

    void printInfo() const override {
        cout << *this << ", Company: " << company << ", Position: " << position << endl;
    }
};

class UserInterface {
private:
    vector<Person*> people;

public:
    void addPerson(Person* person) {
        people.push_back(person);
    }

    void listPeople() const {
        for (auto p : people) {
            p->printInfo();
        }
    }

    void saveToFile(const string& fileName) {
        ofstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error!" << endl;
            return;
        }

        for (auto p : people) {
            file << *p << endl;
        }

        file.close();
    }
};

int main() {
    system("chcp 1251");
    UserInterface users;
    users.addPerson(new Student("Иван", "Иванов", 20, "+7-900-123-45-67", "ИТМО", "Факультет математики"));
    users.addPerson(new Teacher("Марина", "Петрова", 35, "+7-900-987-65-43", "Литература"));
    users.addPerson(new Colleague("Сергей", "Козлов", 30, "+7-900-765-43-21", "Яндекс", "Программист"));
    users.saveToFile("Result");
    users.listPeople();
}