#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  map<char, int> m;
  for (auto c : s) {
    m[c]++;
  }

  int o = 0;
  for (auto [k, v] : m) {
    if (v % 2 != 0) {
      o++;

      if (o > 1) {
        cout << "NO SOLUTION";
        return 0;
      }
    };
  }

  string l, mi, r;

  for (auto [k, v] : m) {
    if (v % 2 != 0) {
      mi = string(v, k);
    } else {
      l += string(v / 2, k);
    }
  }

  r = l;
  reverse(r.begin(), r.end());

  cout << l + mi + r;
};