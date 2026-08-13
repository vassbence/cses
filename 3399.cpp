#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n || (a + b > 0 && (a == 0 || b == 0))) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";

    vector<int> p1(n), p2(n);
    iota(p1.begin(), p1.end(), 1);
    iota(p2.begin(), p2.end(), 1);

    int t = n - a - b;
    rotate(p1.begin() + t, p1.begin() + t + b, p1.end());

    for (int i = 0; i < n; i++) {
      cout << p1[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
      cout << p2[i] << " ";
    }
    cout << "\n";
  }
};