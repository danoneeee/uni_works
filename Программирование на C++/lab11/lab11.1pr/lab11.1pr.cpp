#include <iostream>
using namespace std;

class Distance
{
	friend ostream& operator<< (ostream& out, const Distance& dist);
private:
	int feet;
	float inches;
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0) { }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in) { }
	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << '\ - ' << inches << '\n';
	}
	Distance operator+ (const Distance&) const;
};
ostream& operator<<(ostream& out, const Distance& dist)
{
	out << dist.feet << "' - " << dist.inches << '"';
	return out;
}

Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

int main() {
	system("chcp 1251");
	Distance dist1, dist2, dist3, dist4;
	dist1.getdist();
	dist2.getdist();
	dist3 = dist1 + dist2;
	cout << "\ndist1 = " << dist1;
}
