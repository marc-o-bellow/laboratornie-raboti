#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, z;
    char tc;

	// -4.5 0.000075 -84.5
    cout << "Solve test case? (y/N): ";
    cin >> tc;

    if (tc == 'Y' || tc == 'y') {
        	x = -4.5;
		y = 0.000075;
		z = -84.5;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
    }
    else {
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		cout << "Enter z: ";
		cin >> z;
    }

    double fnum = pow((9 + pow(x - y, 2.0)), 1.0/3.0);
    double fdenum = x*x + y*y + 2.0;
    double term1  = fnum / fdenum;

    double term2 = exp(fabs(x - y)) * pow(tan(z), 3.0);
    double s = term1 - term2;

    // test case result: "Result: s = -3.23765"
    cout << "Result: s = " << s << endl;

    return 0;
}
