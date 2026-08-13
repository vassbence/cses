#include <bits/stdc++.h>

using namespace std;

// slow brute force

// int main() {
//   string s, p;
//   cin >> s >> p;
//
//   int o = 0;
//
//   for (int i = 0; i < (int)s.size(); i++) {
//     if (s[i] == p[0]) {
//       bool m = true;
//       for (int j = 1; j < (int)p.size(); j++) {
//         if (s[i + j] != p[j]) {
//           m = false;
//         }
//       }
//
//       if (m) {
//         o++;
//       }
//     }
//   }
//
//   cout << o;
// };

// fast z algorithm

int main() {
  string s, p;
  cin >> s >> p;

  // put the pattern we are searching as a prefix and add a separator character.
  // now solving the problem becomes finding and counting all the substrings
  // which are also a prefix and match the size of p
  s = p + "#" + s;
  int n = s.size();

  // z algo keeps track of an array which stores the length of the substring
  // which is also a prefix starting at i
  vector<int> z(n);
  // l and r are the bounds of the rightmost match we have found so far
  int l = 0, r = 0;

  for (int i = 1; i < n; i++) {
    // current char we are looking at is inside the bounds of the current match
    // range so we copy over previous knowledge
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }

    // try to make the match as large as possible
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    };

    // if we found a new match we update the bounds
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  cout << count(z.begin(), z.end(), p.size());
}