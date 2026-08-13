#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// a subarraysum is just prefixsum(j) - prefixsum(i) where j > i
// and we are trying to find the largest subarraysum.
// the m variable keeps track of the smallest ever prefixsum and so one endpoint
// is already fixed, now we just need to find the largest prefxisum which we can
// easily do by keeping track of a running total and compating it to a max.

int main() {
  int n;
  cin >> n;

  // t is the aggregated total
  // m is minimum t we ever hit
  // o is the maximum subarray sum
  ll t = 0, m = 0, o = INT_MIN;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    t += x;
    o = max(o, t - m);
    m = min(t, m);
  }

  cout << o;
};