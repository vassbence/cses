#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// if one group has x then the other has total - x
// and we are looking for the minimal difference between x and total - x
// so basically abs(x - (total - x))
// which equals abs(x - total + x)
// which equals abs(2x - total)
// which equals total - 2x

int n;
vector<int> a;
ll t = 0;
ll o = LLONG_MAX;

void solve(int i, ll s) {
  if (i == n) {
    o = min(o, abs(t - 2 * s));
    return;
  }

  solve(i + 1, s + a[i]);
  solve(i + 1, s);
}

int main() {
  cin >> n;
  a.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    t += a[i];
  }

  solve(0, 0);

  cout << o;
};