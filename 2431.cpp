#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;

int main() {
  int q;
  cin >> q;

  while (q--) {
    ll k;
    cin >> k;

    ll l = 1, c = 9, s = 1;

    while (k > l * c) {
      k -= l * c;
      l += 1;
      c *= 10;
      s *= 10;
    }

    string st = to_string(s + (k - 1) / l);
    cout << st[(k - 1) % l] << '\n';
  }
};