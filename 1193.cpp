#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dc[] = {'D', 'U', 'R', 'L'};

int main() {
  int n, m, si = 0, sj = 0;
  cin >> n >> m;

  vector<string> g(n);
  vector<vector<int>> p(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'A') {
        si = i;
        sj = j;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push({si, sj});
  g[si][sj] = '#';

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int i = curr.first;
    int j = curr.second;

    if (g[i][j] == 'B') {
      string o = "";

      while (i != si || j != sj) {
        int k = p[i][j];
        o += dc[k];
        i -= dx[k];
        j -= dy[k];
      }
      reverse(o.begin(), o.end());

      cout << "YES\n" << o.size() << "\n" << o;
      return 0;
    }

    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];

      if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] != '#') {
        p[ni][nj] = k;

        if (g[ni][nj] != 'B') {
          g[ni][nj] = '#';
        }

        q.push({ni, nj});
      }
    }
  }

  cout << "NO";
}