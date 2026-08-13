#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
  int n;
  cin >> n;

  vector<ll> p(n);
  for (ll i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p.begin(), p.end());
  ll g = p[n / 2];

  ll o = 0;

  for (int i = 0; i < n; i++) {
    o += abs(p[i] - g);
  }

  cout << o;
};