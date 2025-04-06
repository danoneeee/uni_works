#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");



	const int N = 10;

	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

	ofstream out("sort.txt");

	if (!out) {
		cout << "File imposible to open\n";
		return 1;
	}


	for (int i : a)
		out << i << '\t';

	

	int min = 0;
	int buf = 0;

	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		{
			if (i != min)
			{
				buf = a[i];
				a[i] = a[min];
				a[min] = buf;

			}


		}
	}

	out << endl << "Sorted: " << endl;
	for (int i : a)
		out << i << '\t';

	out.close();

	cout << "Отсортировано в файл sort.txt";

	return 0;
}

