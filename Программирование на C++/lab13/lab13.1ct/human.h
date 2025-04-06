#include <string>
#include <sstream>
#include <iostream>
#pragma once
using namespace std;
class human {
public:

	human(string last_name, string name, string
		second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	string get_full_name()
	{
		ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;
		return full_name.str();
	}
	virtual void GetInfo()
	{
		cout << "ÔÈÎ: " << get_full_name() << endl;
	}
private:
	string name;
	string last_name;
	string second_name;
};
