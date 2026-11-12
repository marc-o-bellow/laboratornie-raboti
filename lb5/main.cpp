#include <iomanip>
#include <iostream>

using namespace std;

/*
int main() {
  int N, M;
  float buff;

  while (1) {
    cout << "enter size of the matrix: "<< endl;
    cout << "N = ";
    cin >> N;
    cout << "M = ";
    cin >> M;

    if (N > 0 && M > 0) {
      break;
    }
    cout << endl << "Error: matrix size cannot be smaller than 1!" << endl;
    cout << "try again..." << endl << endl;
  }

  char *arr = new char[size];

  for (int i = 0; i < size; i++) {
    cout << "a[" << i << "] = ";
    cin >> arr[i];
  }

  for (int i = 0; i <= size / 2; i++) {
    buff = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = buff;
  }
  cout << endl << "-----" << endl;

  for (int i = 0; i < size; i++) {
    cout << "a[" << i << "] = " << arr[i] << endl;
  }

  delete[] arr;
  arr = nullptr;
  return 0;
}
*/

int main() {
  int N, M;

  while (1) {
    cout << "enter size of the matrix: " << endl;
    cout << "N = ";
    cin >> N;
    cout << "M = ";
    cin >> M;

    if (N > 0 && M > 0) {
      break;
    }
    cout << endl << "ERROR: matrix size cannot be smaller than 1!" << endl;
    cout << "try again..." << endl << endl;
  }

  int **A = new int *[N];
  for (int i = 0; i < N; i++)
    A[i] = new int[M];

  int *B = new int[N];

  cout << "\nrnter the matrix: \n";
  for (int i = 0; i < N; i++) {
    cout << "row " << i + 1 << ": ";
    for (int j = 0; j < M; j++)
      cin >> A[i][j];
  }

  for (int k = 0; k < N; k++) {
    B[k] = 1;
    for (int j = 0; j < M - 1; j++) {
      if (A[k][j] <= A[k][j + 1]) {
        B[k] = 0;
        break;
      }
    }
  }

  cout << "\nmatrix A (size: " << N << "x" << M << "):" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cout << setw(6) << A[i][j];
    cout << '\n';
  }

  cout << "\narray B:\n";
  cout << setw(6) << "k" << setw(10) << "B[k]" << '\n' << endl;
  for (int k = 0; k < N; k++)
    cout << setw(6) << k + 1 << setw(10) << B[k] << '\n';

  for (int i = 0; i < N; i++)
    delete[] A[i];

  delete[] A;
  delete[] B;
  A = nullptr;
  B = nullptr;

  return 0;
}
