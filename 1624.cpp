#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector<int>> r(8, vector<int>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;

      r[i][j] = c == '*';
    }
  }

  int o = 0;
  vector<int> p(8);
  iota(p.begin(), p.end(), 0);

  do {
    bool c = true;

    for (int i = 0; i < 8; i++) {
      if (r[i][p[i]]) {
        c = false;
      }

      for (int j = 0; j < i; j++) {
        if (abs(i - j) == abs(p[i] - p[j]))
          c = false;
      }
    }

    if (c) {
      o++;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << o;
};