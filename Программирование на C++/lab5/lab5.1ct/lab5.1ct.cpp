#include <iostream>

using namespace std;

void show_array(const int Arr[], const int N)
{
	for (int i = 0; i < N; i++) {
		cout << Arr[i] << " ";
		cout << "\t";
	}
}

void ch_sort(int mas[], const int n)
{
	int min = 0;
	int buf = 0;

	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			min = (mas[j] < mas[min]) ? j : min;
		{
			if (i != min)
			{
				buf = mas[i];
				mas[i] = mas[min];
				mas[min] = buf;
			}
		}
	}
	show_array(mas, n);
}

int mas_sum(int mas[], const int n)
{
	double s = 0;
	for (int i = 0; i < n; i++) {
		s += mas[i];
	}
	return s;
}

int sum_ot(int mas[], const int n)
{
	int sum_ot = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			sum_ot += mas[i];
		}
	}
	return sum_ot;
}

int sum_pol(int mas[], const int n)
{

	int sum_pol = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > 0) {
			sum_pol += mas[i];
		}
	}

	return sum_pol;
}

int sum_nechet(int mas[], const int n)
{
	int sum_nechet = 0;
	for (int i = 1; i < n; i += 2) {
		sum_nechet += mas[i];
	}
	return sum_nechet;
}

int sum_chet(int mas[], const int n)
{
	int sum_chet = 0;
	for (int i = 0; i < n; i += 2) {
		sum_chet += mas[i];
	}
	return sum_chet;
}

int max_elem(int mas[], const int n) {
	int max_elem = mas[0];
	int max_elem_indx;
	for (int i = 0; i < n; i++) {
		if (mas[i] >= max_elem) {
			max_elem_indx = i;
			max_elem = mas[i];
		}
	}
	return max_elem_indx;
}

int min_elem(int mas[], const int n)
{
	int min_elem = mas[0];
	int min_elem_indx;
	for (int i = 0; i < n; i++) {
		if (mas[i] <= min_elem) {
			min_elem_indx = i;
			min_elem = mas[i];
		}
	}
	return min_elem_indx;
}

int multi_mas(int mas[], const int n, int max_elem_indx, int min_elem_indx)
{
	int multi_mas = 1;
	if (min_elem_indx < max_elem_indx) {
		for (min_elem_indx; min_elem_indx < max_elem_indx; min_elem_indx++) {
			multi_mas *= mas[min_elem_indx];
		}
	}
	if (min_elem_indx > max_elem_indx) {
		for (max_elem_indx; max_elem_indx < min_elem_indx; max_elem_indx++) {
			multi_mas *= mas[max_elem_indx];
		}
	}

	return multi_mas;
}

int sr_zn(int mas[], const int n, int mas_sum) {
	double sum_mas = mas_sum;
	int sr_zn = sum_mas / n;

	return sr_zn;
}

int main()
{
	const int n = 10;

	int mas[n];

	for (int i = 0; i < n; i++) {
		cout << "mass[" << i << "] = ";
		cin >> mas[i];
	}

	int s = mas_sum(mas, n);
	int sr_znach = sr_zn(mas, n, s);
	int pol = sum_pol(mas, n);
	int ot = sum_ot(mas, n);
	int nechet = sum_nechet(mas, n);
	int chet = sum_chet(mas, n);
	int max = max_elem(mas, n);
	int min = min_elem(mas, n);
	int multi = multi_mas(mas, n, max, min);


	cout << "mas_sum = " << s << endl;
	cout << "sr_zn = " << sr_znach << endl;
	cout << "sum_ot = " << ot << endl << "sum_pol = " << pol << endl << "sum_nechet = " << nechet << endl << "sum_chet = " << chet << endl;
	cout << "max_elem_indx = " << max << endl;
	cout << "min_elem_indx = " << min << endl;
	cout << "milti_mas = " << multi << endl;

	ch_sort(mas, n);

}

