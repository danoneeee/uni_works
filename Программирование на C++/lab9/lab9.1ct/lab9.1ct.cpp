#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Triangle {
private:
	double Sidea, Sideb, Sidec;
public:
	class ExScore
	{
	public:
		string origin;
		double value;
		ExScore(string orr, double sc) {
			origin = orr;
			value = sc;
		}
	};

	Triangle(double a, double b, double c) {
		setSides(a, b, c);
	}

	void setSides(double a, double b, double c) {
		if (a <= 0 ) {
			throw ExScore(" error side a", a);
		}
		if ( b <= 0 ) {
			throw ExScore(" error side b", b);
		}
		if ( c <= 0) {
			throw ExScore(" error side c", c);
		}
		if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
			throw ExScore(" error sum ", max(max(a, b), c));
		}
		Sidea = a;
		Sideb = b;
		Sidec = c;
	}

    double TrSq() {
        double pol_p = (Sidea + Sideb + Sidec) / 2;
        double s = sqrt(pol_p * (pol_p - Sidea) * (pol_p - Sideb) * (pol_p - Sidec));
		return s;
    }
};


int main()
{
	try {
		Triangle triangle1(3,4,-8);
		double s1;
		s1 = triangle1.TrSq();
		cout << "Square: " << s1 << endl;
	}

	catch (Triangle::ExScore& ex)
	{
		cout << "\nError:" << ex.origin;
		cout << "\nInvalid value -> " << ex.value;
	}
}
