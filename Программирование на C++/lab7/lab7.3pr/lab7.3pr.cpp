#include <iostream>

using namespace std;


struct Distance
{
	int feet;
	int inches;
};

Distance InputDist()
{
	Distance d;
	cout << "\nВведите число футов: ";
	cin >> d.feet;
	cout << "\nВведите число дюймов: ";
	cin >> d.inches;
	return d;
}

void ShowDist(Distance d)
{
	cout << d.feet << "\'-" << d.inches << "\"\n";
}


int main()
{

	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите размер массива: ";
	cin >> n;

	Distance * masDist = new Distance[n];

	for (int i = 0; i < n; i++)
	{
		masDist[i] = InputDist();
	}

	for (int i = 0; i < n; i++)
	{
		ShowDist(masDist[i]);
	}

	delete[] masDist;

}
