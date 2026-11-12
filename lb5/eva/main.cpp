#include <clocale>
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru");
  int N, M;

  cout << "Введите количество строк N: ";
  cin >> N;
  cout << "Введите количество столбцов M: ";
  cin >> M;

  int **A = new int *[N];
  for (int i = 0; i < N; ++i)
    A[i] = new int[M];

  cout << "\nВведите элементы матрицы:\n";
  for (int i = 0; i < N; ++i) {
    cout << "Строка " << i + 1 << ": ";
    for (int j = 0; j < M; ++j)
      cin >> A[i][j];
  }

  int maxSnizu = 0, minSverhu = 0;
  bool foundBelow = false, foundAbove = false;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {

      if (i + j > M - 1) {
        if (!foundBelow || A[i][j] > maxSnizu) {
          maxSnizu = A[i][j];
          foundBelow = true;
        }
      }

      if (j > i) {
        if (!foundAbove || A[i][j] < minSverhu) {
          minSverhu = A[i][j];
          foundAbove = true;
        }
      }
    }
  }

  cout << "\nМатрица A (" << N << "x" << M << "):\n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j)
      cout << A[i][j] << "  ";
    cout << '\n';
  }

  cout << "\nРезультат:\n";
  if (foundBelow)
    cout << "Максимум ниже побочной диагонали: " << maxSnizu << '\n';
  else
    cout << "Ниже побочной диагонали элементов нет\n";

  if (foundAbove)
    cout << "Минимум выше главной диагонали:   " << minSverhu << '\n';
  else
    cout << "Выше главной диагонали элементов нет\n";

  for (int i = 0; i < N; ++i)
    delete[] A[i];
  delete[] A;

  return 0;
}
