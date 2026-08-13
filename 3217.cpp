#include <bits/stdc++.h>

using namespace std;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
  int n;
  cin >> n;

  vector<vector<int>> b(n, vector<int>(n, -1));
  queue<pair<int, int>> q;

  b[0][0] = 0;
  q.push({0, 0});

  while (q.size()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nr = r + dr[i], nc = c + dc[i];

      if (nr > -1 && nr < n && nc > -1 && nc < n && b[nr][nc] == -1) {
        b[nr][nc] = b[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
}
