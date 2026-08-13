#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int M = 100 + 1;
const int MOD = 1e9 + 7;

// represents the count of distinct n sized arrays we can have where the nth
// element equals m
int dp[N][M];

int main() {
  int n, m;
  cin >> n >> m;

  // making x 1 indexed for ease of use later
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  // if the first number is we can have an 1 sized array m ways
  // or if x is not 0 then 1 sized arrays can only be created with a specific i
  // in one way
  for (int i = 1; i <= m; i++) {
    if (x[1] == 0 || x[1] == i) {
      dp[1][i] = 1;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i] == 0 || x[i] == j) {
        // since the absolute difference between two adjacent values can at most
        // be one we only have to check -1, 0 and 1 diffs
        for (int k = -1; k <= 1; ++k) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % MOD;
        }
      }
    }
  }

  int o = 0;
  for (int j = 1; j <= m; ++j) {
    o = (o + dp[n][j]) % MOD;
  }
  cout << o;
};