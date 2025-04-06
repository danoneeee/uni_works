#include <iostream>

using namespace std;

void show_array(const int Arr[], const int N)
{
	for (int i = 0; i < N; i++) {
		cout << Arr[i] << " ";
		cout << "\t";
	}
}

bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if ((*compare) (Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
		}
	}
}

int main()
{
	const int N = 10;
	int my_choose = 0;

	bool (*from_f[2])(int, int) = { from_min, from_max };

	int n;
	cout << "Enter elements number: ";
	cin >> n;


	int* A = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

	cout << "1. Sort from down to up\n";
	cout << "2. Sort from up to down\n";

	cin >>  my_choose;

	cout << "Ishodnaya data:\n";

	show_array(A, n);

	cout << "\n";

	/*switch (my_choose)
	{
	case 1: bubble_sort(A, N, from_min); break;
	case 2: bubble_sort(A, N, from_max); break;
	default: cout << "\r UNKNOWN OPERATION!";
	}*/

	bubble_sort(A, n, (from_f[my_choose - 1]));

	cout << "Sorted Arr: \n";

	show_array(A, n);


	delete[] A;
	A = nullptr;

	return 0;
}