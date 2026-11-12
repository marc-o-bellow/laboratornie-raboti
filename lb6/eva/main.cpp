#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char st[100], first[100], second[100];
  int k;

  cout << "Введите текст: ";
  cin.getline(st, 100);

  cout << "Введите значение k: ";
  cin >> k;

  int n = strlen(st);

  if (k > n)
    k = n;
  int p = k;

  if (p > 0 && p < n && st[p - 1] != ' ' && st[p] != ' ') {
    while (p > 0 && st[p - 1] != ' ')
      p--;
  }

  strncpy(first, st, p);
  first[p] = '\0';

  while (st[p] == ' ')
    p++;
  strcpy(second, st + p);

  cout << "Первая подстрока: \"" << first << "\" (размер: " << strlen(first)
       << ")" << endl;
  cout << "Вторая подстрока: \"" << second << "\" (размер: " << strlen(second)
       << ")" << endl;

  return 0;
}
