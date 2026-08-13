#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long int c, p, o = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cin >> p;
    } else {
      cin >> c;

      if (c < p) {
        o += p - c;
      } else {
        p = c;
      }
    }
  }

  cout << o << '\n';
};