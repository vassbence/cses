#include <bits/stdc++.h>

using namespace std;

// slow brute force

// int main() {
//   string s;
//   cin >> s;
//   int n = (int)s.size();
//
//   for (int i = 0; i < n - 1; i++) {
//     bool o = true;
//
//     for (int j = 0; j <= i; j++) {
//       if (s[j] != s[n - 1 - i + j]) {
//         o = false;
//       };
//     }
//
//     if (o) {
//       cout << i + 1 << ' ';
//     }
//   }
// };

// optimal z algorithm

int main() {
  string s;
  cin >> s;
  int n = s.size();

  // basic z algo implementation
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    };

    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  // then iterating backwards (for correct increasing order)
  // and printing the size of all substrings which are prefixes and end at the
  // end of the string
  for (int i = n - 1; i >= 1; i--) {
    if (z[i] == n - i) {
      cout << z[i] << ' ';
    }
  }
}