#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

using Function = double (*)(double, double, int &);

double y(double x) {
  return sin(x) / x;
}

double y(double x, double, int &k) {
  k = 0;
  return y(x);
}

double s(double x, double eps, int &k) {
  double sum = 1.0;
  double term = 1.0;
  k = 0;

  for (int i = 1; ; ++i) {
    term *= -x * x / ((2.0 * i) * (2.0 * i + 1.0));
    if (abs(term) <= eps)
      return sum;

    sum += term;
    ++k;
  }
}

void tabl(double a, double b, double h, double eps, Function exact,
          Function series) {
  cout << setw(6) << "x" << setw(15) << "Y(x)" << setw(15) << "S(x)"
       << setw(5) << "k" << '\n';

  const int steps = static_cast<int>(round((b - a) / h));
  cout << fixed;
  for (int i = 0; i <= steps; ++i) {
    const double x = a + i * h;
    int k;
    const double exactValue = exact(x, eps, k);
    const double seriesValue = series(x, eps, k);
    cout << setw(6) << setprecision(1) << x << setprecision(8)
         << setw(15) << exactValue << setw(15) << seriesValue << setw(5) << k
         << '\n';
  }
}

int main() {
  tabl(0.1, 0.9, 0.1, 1e-5, y, s);
  return 0;
}
