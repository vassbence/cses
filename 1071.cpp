#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long y, x;
    cin >> y >> x;

    long long l = max(y, x);
    long long o;

    // even layer
    if (l % 2 == 0) {
      // horizontal
      if (l == y) {
        o = l * l - x + 1;
      }
      // vertical
      else {
        o = (l - 1) * (l - 1) + y;
      }
    }
    // odd layer
    else {
      // horizontal
      if (l == y) {
        o = (l - 1) * (l - 1) + x;
      }
      // vertical
      else {
        o = l * l - y + 1;
      }
    }

    cout << o << '\n';
  }
};