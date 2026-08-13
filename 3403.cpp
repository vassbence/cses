#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  // dp[i][j] represents the length of the largest possible common subsequence
  // of the first i elements of a and the first j elements of b
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // to find a sequence we have to backtrack the dp array
  vector<int> o;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      o.push_back(a[i - 1]);
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    }
    // this checks for when the left index was larger or that both left and
    // right were the same value (in the latter case it does not matter which
    // one we pick, because both cells represent that there are the same amount
    // of subsets either way we go.)
    else {
      j--;
    }
  }

  cout << dp[n][m] << '\n';
  // we have to print in reverse order
  for (int i = (int)o.size() - 1; i >= 0; i--) {
    cout << o[i] << ' ';
  }
};