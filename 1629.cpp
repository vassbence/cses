#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> m(n);

  for (int i = 0; i < n; ++i) {
    cin >> m[i].first >> m[i].second;
  }

  sort(m.begin(), m.end(), [](auto a, auto b) { return a.second < b.second; });

  int o = 0;
  int t = 0;

  for (int i = 0; i < n; i++) {
    if (m[i].first >= t) {
      o++;
      t = m[i].second;
    };
  }

  cout << o;
};