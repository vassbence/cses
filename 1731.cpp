#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 1e6;
int trie[N][26];
int terminal[N];
int nid = 1;

int main() {
  string s, w;
  int k;
  cin >> s >> k;

  for (int i = 0; i < k; i++) {
    cin >> w;

    int curr = 0;
    for (int j = 0; j < (int)w.size(); j++) {
      int c = w[j] - 'a';

      if (!trie[curr][c]) {
        trie[curr][c] = nid;
        nid += 1;
      }

      curr = trie[curr][c];
    }

    terminal[curr] = 1;
  }

  int dp[N + 1];
  fill(begin(dp), end(dp), 0);
  dp[0] = 1;

  for (int i = 0; i < (int)s.size(); i++) {
    int curr = 0;

    for (int j = i; j < (int)s.size(); j++) {
      int c = s[j] - 'a';

      if (!trie[curr][c]) {
        break;
      }

      curr = trie[curr][c];

      if (terminal[curr]) {
        dp[j + 1] = (dp[j + 1] + dp[i]) % M;
      }
    }
  }

  cout << dp[s.size()];
};