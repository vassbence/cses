#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
  int n;
  cin >> n;

  ll m = 0;
  ll s = 0;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;

    s += t;
    m = max(m, t);
  }

  if (m > s - m) {
    cout << 2 * m;
  } else {
    cout << s;
  }
}