#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (char c : to_string(i)) {
      // convert to int via ascii table ('0' is 48, '5' is 53)
      int d = c - '0';

      dp[i] = min(dp[i], dp[i - d] + 1);
    }
  }

  cout << dp[n];
}