#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int o = 1;

  for (int i = 0; i < n; i++) {
    o = (o * 2) % (int)(1e9 + 7);
  }

  cout << o << '\n';
};