#include <iostream>
using namespace std;

class Distance
{
	const float MTF;
	friend ostream& operator<< (ostream& out, const Distance& dist);
private:
	int feet;
	float inches;
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F)
	{ }
	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // перевод в футы
		feet = int(fltfeet); // число полных футов
		inches = 12 * (fltfeet - feet); // остаток - это дюймы
	}
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
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
	Distance dist1 = 2.35F;
	float mtrs;
	cout << dist1 << endl;

	mtrs = dist1;
	cout << mtrs << endl;
	//cout << "\ndist2 = " << dist2;
}
