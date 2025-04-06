#include "human.h"
#include <string>
#include <iostream>
class teacher : public human {
public:
	teacher(
		string last_name,
		string name,
		string second_name,
		unsigned int work_time) : human(last_name, name, second_name) {
		this->work_time = work_time;
	}
	unsigned int get_work_time()
	{
		return this->work_time;
	}
	virtual void GetInfo()
	{
		human::GetInfo();
		cout << "Время работы: " << get_work_time() << endl;
	}
private:
	unsigned int work_time;
};