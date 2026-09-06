#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> x(n);
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
    s += x[i];
  }

  // let sum of player 1's picks be `a`, player 2's `b`
  // a + b = s
  // a - b = diff
  // (a + b) + (a - b) = s + diff
  // 2a = s + diff
  // a = (s + diff) / 2

  // stores max diff for a given i, j subarray
  vector<vector<long long>> dp(n, vector<long long>(n, 0));

  // base case for 1 length subarrays.
  for (long long i = 0; i < n; i++) {
    dp[i][i] = x[i];
  }

  for (long long len = 2; len <= n; len++) {
    for (long long i = 0; i <= n - len; i++) {
      long long j = i + len - 1;
      // take left (x[i]) or take right (x[j]) and subtract the max diff of the
      // remainders, then take whichever is larger
      dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
    }
  }

  cout << (s + dp[0][n - 1]) / 2 << "\n";
}