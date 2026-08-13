#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  };

  sort(x.begin(), x.end());

  ll s = 0;
  for (int i = 0; i < n; i++) {
    // if the next number is 1 larger than the current sum then we can't "bridge
    // the gap" and create that sum with current elements so we found our
    // smallest missing sum
    // note: if the problem would ensure that every x is unique we could do !=
    // here because we are basically "expecting" a value, we know exactly that
    // we need s+1 to be able to continue having a full sequence
    if (x[i] > s + 1) {
      break;
    }

    s += x[i];
  }

  cout << s + 1;
};