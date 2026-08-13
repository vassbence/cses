#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      set<int> s;

      for (int k = i - 1; k > -1; k--) {
        s.insert(g[k][j]);
      }
      for (int k = j - 1; k > -1; k--) {
        s.insert(g[i][k]);
      }

      int c = 0;
      while (s.count(c)) {
        c++;
      }

      g[i][j] = c;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << g[i][j] << ' ';
    }
    cout << '\n';
  }
}