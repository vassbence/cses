#include <bits/stdc++.h>

using namespace std;

// fast doubling as per https://www.nayuki.io/page/fast-fibonacci-algorithms

typedef long long ll;

const ll M = 1e9 + 7;

pair<ll, ll> f(ll n) {
  if (n == 0) {
    return {0, 1};
  };

  auto p = f(n / 2);

  ll a = p.first;
  ll b = p.second;
  ll c = a * (2 * b - a + M) % M;
  ll d = (a * a + b * b) % M;

  if (n % 2 == 0) {
    return {c, d};
  }

  return {d, (c + d) % M};
}

int main() {
  ll n;

  cin >> n;

  cout << f(n).first;
}