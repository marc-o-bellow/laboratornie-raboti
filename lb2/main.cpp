#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
  int ifunc = 0;

  double x, y, id, f, result;

  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;
  cout << "Choose f(x):\n 1. sh(x)\n 2. x^2\n 3. e^x" << endl;
  cout << "Enter f: ";
  cin >> ifunc;

  switch (ifunc) {
  case 1:
    f = sinh(x);
    break;
  case 2:
    f = pow(x, 2);
    break;
  case 3:
    f = exp(x);
    break;

  default:
    cout << "Wrong function number. Exiting..." << endl;
    return 1;
  }

  id = x / y;
  if (id > 0) {
    cout << "\nSolving ln(f(x)) + pow(|f(x)| ,1.0/3)\nBecause x/y = " << id
         << " > 0" << endl;
    result = log(f) + pow(fabs(f), 1.0 / 3);
  } else if (id < 0) {
    cout << "Solving log( |f(x)/y| ) * (x + y)^3\nBecause x/y = " << id
         << " < 0" << endl;
    result = log(fabs(f / y)) * pow(x + y, 3);
  } else {
    cout << "Solving (f^2(x) + y)^3\nBecause x/y = " << id << " is other case."
         << endl;
    result = pow(pow(f, 2) + y, 3);
  }

  cout << "Result: " << result << endl;
  return 0;
}
