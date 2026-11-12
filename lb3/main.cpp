#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double a = 0.1, b = 1, x, y, s, p;
  double h = (b - a) / 10;
  int n = 100;
  x = a;
  cout << "+-----------------------------------------+" << endl;
  cout << "|" << setw(6) << "x" << " |" << setw(15) << "Y(x)" << " |"
       << setw(17) << "  S(x) |" << endl;
  cout << "|-------+----------------+----------------|" << endl;
  do {
    p = 1;
    s = 1;
    for (int i = 1; i <= n; i++) {
      p *= x * x / ((2 * i - 1) * (2 * i));
      s += p;
    }
    y = (exp(x) + exp(-x)) / 2;
    cout << "|" << setw(6) << x << " |" << setw(15) << y << " |" << setw(15)
         << s << " |" << endl;
    x += h;
  } while (x <= b + h / 2);
  cout << "+-----------------------------------------+" << endl;
  return 0;
}
