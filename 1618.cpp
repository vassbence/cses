#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  // Legendre's formula
  int o = 0;

  while (n >= 5) {
    o += n / 5;
    n = n / 5;
  }

  cout << o << '\n';
};