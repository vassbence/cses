#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  // m represents size of longest sequence of successive unique songs so far
  // s represents start of the current sequence of successive unique songs
  int m = 0, s = 0;
  set<int> c;

  for (int i = 0; i < n; i++) {
    // if the song is already in the current sequence then have to start
    // removing items from the start until it's not in the current sequence
    // anymore. this is because we need a list of successive unique songs.
    while (c.count(k[i])) {
      c.erase(k[s]);
      s++;
    }

    c.insert(k[i]);
    m = max(m, (int)c.size());
  }

  cout << m;
};