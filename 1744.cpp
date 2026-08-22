#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  // dp[i][j] represents the minimum amount of moves required to transform an
  // a*b rectangle into squares
  vector<vector<int>> dp(a + 1, vector<int>(b + 1));

  for (int i = 1; i < a + 1; i++) {
    for (int j = 1; j < b + 1; j++) {
      // if it's already a square there are 0 moves required
      if (i == j) {
        dp[i][j] = 0;
      } else {
        int m = INT_MAX;

        // vertical
        for (int k = 1; k < j; ++k) {
          m = min(m, 1 + dp[i][k] + dp[i][j - k]);
        }

        // horizontal
        for (int k = 1; k < i; ++k) {
          m = min(m, 1 + dp[k][j] + dp[i - k][j]);
        }

        dp[i][j] = m;
      }
    }
  }

  cout << dp[a][b] << "\n";
}