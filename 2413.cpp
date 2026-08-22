#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6;

// dp[i][j] represents the number of possible towers with height i where the top
// layer has layout j.
// layout type 0 is two 1x1s, layout type 1 is one 2x1
long long dp[N + 1][2];

// fills the dp array
void f() {
  // base cases:
  dp[1][0] = 1; // two 1x1
  dp[1][1] = 1; // one 2x1

  for (int i = 1; i < N; i++) {
    // if we want a 1x1 row at the top:
    // if the prev row was 1x1s we have a choice of adding new block or
    // extending the existing block upwards -> 4 possibilities
    // if it was a 2x1 then we must just add two 1x1s
    dp[i + 1][0] = (4 * dp[i][0] + dp[i][1]) % MOD;

    // if we want a 2x1 row at the top
    // and the previous row had two 1x1s we must add a 2x1
    // or if the prev row was a 2x1 we can extend the existing block upwards or
    // add a new one
    dp[i + 1][1] = (dp[i][0] + 2 * dp[i][1]) % MOD;
  }
}

int main() {
  int t;
  cin >> t;

  f();

  while (t--) {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
  }
}