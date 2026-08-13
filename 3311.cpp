#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (s[j] == 'A') {
          cout << 'B';
        } else {
          cout << 'A';
        }
      } else {
        if (s[j] == 'C') {
          cout << 'D';
        } else {
          cout << 'C';
        }
      }
    }

    cout << '\n';
  }
};
