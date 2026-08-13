#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> t;

void dfs(int i, int j) {
  // bounds checking
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return;
  }

  // skipping already visited ('.') or wall('#') tiles
  if (t[i][j] != '.') {
    return;
  }

  // marking tile as visited
  t[i][j] = 'v';

  // recursively go in all directions to mark every '.' in the room as visited
  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int main() {
  cin >> n >> m;

  t.resize(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
    }
  }

  int o = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // we count it as a new room then use dfs to mark every tile of room as
      // visited
      if (t[i][j] == '.') {
        o++;
        dfs(i, j);
      }
    }
  }

  cout << o;
};