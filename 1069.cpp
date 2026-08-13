#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int c = 1, m = 1;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] == s[i - 1]) {
      c++;
    } else {
      c = 1;
    }

    if (c > m) {
      m = c;
    }
  }

  cout << m << '\n';
};