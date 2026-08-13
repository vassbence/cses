#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i].first >> t[i].second;
  }

  sort(t.begin(), t.end());

  ll ct = 0;
  ll o = 0;

  for (int i = 0; i < n; i++) {
    ct += t[i].first;
    o += t[i].second - ct;
  }

  cout << o;
};