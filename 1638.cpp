#include <bits/stdc++.h>

using namespace std;

// classic dp

// int main() {
//   int m = 1e9 + 7;
//   int n;
//   cin >> n;

//   vector<vector<bool>> t(n, vector<bool>(n));
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       char c;
//       cin >> c;
//       t[i][j] = c == '*' ? true : false;
//     }
//   }

//   vector<vector<int>> dp(n, vector<int>(n));
//   dp[0][0] = t[0][0] ? 0 : 1;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       if (i == 0 && j == 0) {
//         continue;
//       } else if (t[i][j]) {
//         dp[i][j] = 0;
//       } else {
//         if (i > 0) {
//           dp[i][j] = (dp[i][j] + dp[i - 1][j]) % m;
//         }
//         if (j > 0) {
//           dp[i][j] = (dp[i][j] + dp[i][j - 1]) % m;
//         }
//       }
//     }
//   }

//   cout << dp[n - 1][n - 1];
// }

// even cleaner version with single dimension array and streaming input. it is
// basically just recyclying the same array and abuses the fact that while we
// are working on any given row the previous one is still in the array. and
// since we only need the left and the one above this works perfectly fine.
// dp[j-1] contains left (as it was just updated in the previous j iteration)
// and to get above we just have to realize that dp[j] is exactly that from the
// previous i iteration (so previous row)

int main() {
  int n, m = 1e9 + 7;
  cin >> n;

  vector<int> dp(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;

      if (c == '*') {
        dp[j] = 0;
      } else if (i == 0 && j == 0) {
        dp[j] = 1;
      } else if (j > 0) {
        dp[j] = (dp[j] + dp[j - 1]) % m;
      }
    }
  }

  cout << dp[n - 1];
}