// #include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char st[100], sl[100], mn[100];
  int k = 0, minLen = 0;
  bool found = false;

  cout << "Enter the string, containing 1 and 0 (with spaces): ";
  cin.getline(st, 99);

  strcat(st, " ");
  int n = strlen(st);

  sl[0] = '\0';
  mn[0] = '\0';

  for (int i = 0; i < n; i++) {
    if (st[i] != ' ') {
      sl[k] = st[i];
      sl[k + 1] = '\0';
      k++;
    } else {
      int len = strlen(sl);
      if (len > 0) {
        if (!found || len < minLen) {
          strcpy(mn, sl);
          minLen = len;
          found = true;
        }
      }
      sl[0] = '\0';
      k = 0;
    }
  }

  if (found)
    cout << "the shortest group is: " << mn << " (size: " << minLen << ")"
         << endl;
  else
    cout << "there is no groups found!" << endl;

  return 0;
}
