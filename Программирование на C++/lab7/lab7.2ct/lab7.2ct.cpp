#include <iostream>
#include <cmath>


using namespace std;


struct Roots {
	double x1;
	double x2;
};

Roots SqSolve(double a, double b, double c) {
	
	
	double D = b * b - 4 * a * c;
	Roots x;

	if (D > 0)
	{
		x.x1 = (-b + sqrt(D)) / 2 * a;
		x.x2 = (-b - sqrt(D)) / 2 * a;
	}
	else if (D == 0)
	{
		x.x1 = x.x2 = -b / 2 * a;
	}
	else
	{
		x.x1 = NAN;
		x.x2 = NAN;
	}

	return x;

}

void ShowRoots(Roots x) {
	cout << "x_1 = " << x.x1 << "\nx_2 = " << x.x2;
}


int main()
{
	double a, b, c;
	cout << "input a: " << endl;
	cin >> a;
	cout << "input b: " << endl;
	cin >> b;
	cout << "input c: ";
	cin >> c;

	Roots ans;
	ans = SqSolve(a, b, c);

	if (isnan(ans.x1)) 
	{
		cout << "D < 0" << endl;
	}

	else if (ans.x1 == ans.x2) 
	{
		cout << "D = 0" << ans.x1 << endl;
	}

	else 
	{
		ShowRoots(ans);
	}
	return 0;


}
