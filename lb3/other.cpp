#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double a = -2, b = -0.1, x, h = (b - a) / 10, y, s, p, t;
  int n = 16000000;

  x = a;
  do {
    t = 1 + x;  // t = 1 + x
    p = -t * t; // a1 = -t^2/1
    s = p;
    for (int k = 2; k <= n; k++) {
      p *= -t * t * (k - 1) / k; // a_k = -a_(k-1) * t^2 * (k-1)/k
      s += p;
    }
    y = log(1.0 / (2.0 + 2.0 * x + x * x));
    cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
    x += h;
  } while (x <= b + h / 2.0);
  return 0;
}
