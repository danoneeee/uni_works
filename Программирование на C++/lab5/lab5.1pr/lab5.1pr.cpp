#include <iostream>

using namespace std;


int main()
{
	const int n = 10;

	int mas[n];

	for (int i = 0; i < n; i++) {
		cout << "mass[" << i << "] = ";
		cin >> mas[i];
	}

	double s = 0;
	for (int i = 0; i < n; i++) {
		s += mas[i];
	}


	int sum_ot = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			sum_ot += mas[i];
		}
	}

	int sum_pol = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] > 0) {
			sum_pol += mas[i];
		}
	}

	int sum_nechet = 0;
	for (int i = 1; i < n; i += 2) {
		sum_nechet += mas[i];
	}

	int sum_chet = 0;
	for (int i = 0; i < n; i += 2) {
		sum_chet += mas[i];
	}

	int max_elem = mas[0];
	int max_elem_indx;
	for (int i = 0; i < n; i++) {
		if (mas[i] >= max_elem) {
			max_elem_indx = i;
			max_elem = mas[i];
		}
	}

	int min_elem = mas[0];
	int min_elem_indx;
	for (int i = 0; i < n; i++) {
		if (mas[i] <= min_elem) {
			min_elem_indx = i;
			min_elem = mas[i];
		}
	}





	cout << "mas sum = " << s << endl;

	double sr_zn = s / n;

	cout << "sr_zn = " << sr_zn << endl;

	cout << "sum_ot = " << sum_ot << endl << "sum_pol = " << sum_pol << endl << "sum_nechet = " << sum_nechet << endl << "sum_chet = " << sum_chet << endl;

	cout << "max_elem_indx = " << max_elem_indx << endl;
	cout << "min_elem_indx = " << min_elem_indx << endl;

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

	cout << "mutli_mas = " << multi_mas;


}
