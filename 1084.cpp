#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ca = 0, cb = 0, o = 0;

  while (ca < n && cb < m) {
    if (b[cb] >= a[ca] - k && b[cb] <= a[ca] + k) {
      ca++;
      cb++;
      o++;
    } else if (b[cb] < a[ca] - k) {
      cb++;
    } else {
      ca++;
    }
  }

  cout << o;
}