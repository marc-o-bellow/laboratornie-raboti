#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

struct product {
  string name;
  int count;
  int price;
  int day, month, year;
};

bool storedMoreThanMonth(const product &p) {
  tm d = {};
  d.tm_mday = p.day;
  d.tm_mon = p.month - 1;
  d.tm_year = p.year - 1900;
  d.tm_mon += 1;
  d.tm_isdst = -1;
  time_t limit = mktime(&d);
  return difftime(time(nullptr), limit) > 0;
}

bool byName(const product &a, const product &b) { return a.name < b.name; }

int main() {
  const int MAX = 100;
  product list[MAX];
  int n;

  cout << "Vvedite kol-vo tovarov: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Tovar " << i + 1 << endl;
    cout << "  Naimenovanie: ";
    cin >> ws;
    getline(cin, list[i].name);
    cout << "  Kolichestvo: ";
    cin >> list[i].count;
    cout << "  Cena za edinicu: ";
    cin >> list[i].price;
    cout << "  Data postupleniya (dd mm yyyy): ";
    cin >> list[i].day >> list[i].month >> list[i].year;
  }

  product res[MAX];
  int k = 0;
  for (int i = 0; i < n; i++)
    if (list[i].price > 100000 && storedMoreThanMonth(list[i]))
      res[k++] = list[i];

  sort(res, res + k, byName);

  cout << "\nTovary, hranyashchiesya bolshe mesyaca i dorozhe 100000:\n";
  if (k == 0)
    cout << "Takih tovarov net" << endl;
  for (int i = 0; i < k; i++)
    cout << res[i].name << " | kol-vo: " << res[i].count
         << " | cena: " << res[i].price << " | data: " << res[i].day << "."
         << res[i].month << "." << res[i].year << endl;

  return 0;
}
