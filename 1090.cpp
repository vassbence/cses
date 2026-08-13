#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  int l = 0, r = n - 1, o = 0;

  while (l <= r) {
    if (p[l] + p[r] <= x) {
      l++;
      r--;
    } else {
      r--;
    }

    o++;
  }

  cout << o;
};