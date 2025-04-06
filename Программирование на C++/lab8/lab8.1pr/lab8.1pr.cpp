﻿#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	// Установка имени студента
	void set_name(string student_name)
	{
		name = student_name;
	}
	// Получение имени студента
	string get_name()
	{
		return name;
	}
	// Установка фамилии студента
	void set_last_name(string student_last_name)
	{
		last_name = student_last_name;
	}
	// Получение фамилии студента
	string get_last_name()
	{
		return last_name;
	}
	// Установка промежуточных оценок
	void set_scores(int student_scores[])
	{
		for (int i = 0; i < 5; ++i) {
			scores[i] = student_scores[i];
		}
	}
	// Установка среднего балла
	void set_average_score(double ball)
	{
		average_score = ball;
	}
	// Получение среднего балла
	double get_average_score()
	{
		return average_score;
	}
private:
	int scores[5]; // Промежуточные оценки
	double average_score; // Средний балл
	string name; // Имя
	string last_name; // Фамилия
};

int main()
{
	Student student01;

	string name;
	string last_name;
	int scores[5];

	cout << "Name: ";
	getline(cin, name);

	cout << "Last name: ";
	getline(cin, last_name);

	int sum = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}

	student01.set_name(name);
	student01.set_last_name(last_name);
	student01.set_scores(scores);

	double average_score = sum / 5.0;
	student01.set_average_score(average_score);
	cout << "Average ball for " << student01.get_name() << " " << student01.get_last_name() << " is " << student01.get_average_score() << endl;
}