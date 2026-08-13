#include <bits/stdc++.h>

using namespace std;

// 2d dp solution uses too much memory (eg 1000x1000 grid and cells are getting
// increasingly longer strings)

// int main() {
//   int n;
//   cin >> n;

//   vector<string> g(n);
//   for (int i = 0; i < n; i++) {
//     cin >> g[i];
//   }

//   vector<vector<string>> dp(n, vector<string>(n));
//   dp[0][0] += g[0][0];
//   for (int i = 1; i < n; i++) {
//     dp[0][i] = dp[0][i - 1] + g[0][i];
//     dp[i][0] = dp[i - 1][0] + g[i][0];
//   }

//   for (int i = 1; i < n; i++) {
//     for (int j = 1; j < n; j++) {
//       dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
//     }
//   }

//   cout << dp[n - 1][n - 1];
// };

// single dimension dp array solution which is based on the fact that we only
// need the previous row and the left element for each step.
// this is almost good but still way too much cpu wasted on creating strings

// int main() {
//   int n;
//   cin >> n;

//   vector<string> g(n);
//   for (int i = 0; i < n; i++) {
//     cin >> g[i];
//   }

//   vector<string> dp(n);
//   dp[0] += g[0][0];
//   for (int i = 1; i < n; i++) {
//     dp[i] = dp[i - 1] + g[0][i];
//   }

//   for (int i = 1; i < n; i++) {
//     // first element in the row can only come from the row above so we set it
//     by
//     // hand
//     dp[0] = dp[0] + g[i][0];

//     // process the rest of the row
//     for (int j = 1; j < n; j++) {
//       // dp[j] is the value from the row above (i-1)
//       // dp[j-1] is the value from the left (current row i)
//       dp[j] = min(dp[j], dp[j - 1]) + g[i][j];
//     }
//   }

//   cout << dp[n - 1];
// }

// above solution still TLE so we need to optimize further

int main() {
  int n;
  cin >> n;

  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  // dp[i][j] is true if the cell is on the lexicographically smallest path
  vector<vector<bool>> dp(n, vector<bool>(n));
  dp[0][0] = true;

  string o;
  o += g[0][0];

  // to get from (0,0) to (n-1,n-1) thats 2n-2 steps
  for (int i = 1; i <= 2 * n - 2; i++) {
    // best so far, initialzed to 1 after our alphabet
    char b = 'Z' + 1;

    // bounds of current anti-diagonal
    int s = max(0, i - n + 1);
    int e = min(i, n - 1);

    for (int j = s; j <= e; j++) {
      int r = j;
      int c = i - j;

      if ((r > 0 && dp[r - 1][c]) || (c > 0 && dp[r][c - 1])) {
        b = min(b, g[r][c]);
      }
    }

    o += b;

    for (int j = s; j <= e; j++) {
      int r = j;
      int c = i - j;

      if (((r > 0 && dp[r - 1][c]) || (c > 0 && dp[r][c - 1])) &&
          g[r][c] == b) {
        dp[r][c] = true;
      }
    }
  }

  cout << o;
}
