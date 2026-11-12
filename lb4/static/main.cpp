#include <iostream>

using namespace std;

int main() {
  const int n = 100;
  int size;
  float buff;

  while (1) {
    cout << "enter size of the array: ";
    cin >> size;

    if (size > 0) {
      break;
    }
    cout << endl << "Error: array size cannot be smaller than 1!" << endl;
    cout << "try again..." << endl << endl;
  }

  float arr[n] = {0};

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

  return 0;
}
