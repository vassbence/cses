#include <bits/stdc++.h>

using namespace std;

string s;
bool g[7][7];
int o = 0;

void solve(int r, int c, int n) {
  if (r == 6 && c == 0) {
    if (n == 48) {
      o += 1;
    }
    return;
  }

  if (n == 48) {
    return;
  }

  if ((r == 0 || r == 6 || (g[r - 1][c] && g[r + 1][c])) && c > 0 && c < 6 &&
      !g[r][c - 1] && !g[r][c + 1]) {
    return;
  }
  if ((c == 0 || c == 6 || (g[r][c - 1] && g[r][c + 1])) && r > 0 && r < 6 &&
      !g[r - 1][c] && !g[r + 1][c]) {
    return;
  }

  g[r][c] = true;

  if ((s[n] == 'U' || s[n] == '?') && r > 0 && !g[r - 1][c]) {
    solve(r - 1, c, n + 1);
  }
  if ((s[n] == 'D' || s[n] == '?') && r < 6 && !g[r + 1][c]) {
    solve(r + 1, c, n + 1);
  }
  if ((s[n] == 'L' || s[n] == '?') && c > 0 && !g[r][c - 1]) {
    solve(r, c - 1, n + 1);
  }
  if ((s[n] == 'R' || s[n] == '?') && c < 6 && !g[r][c + 1]) {
    solve(r, c + 1, n + 1);
  }

  g[r][c] = false;
};

int main() {
  cin >> s;

  solve(0, 0, 0);

  cout << o;
};