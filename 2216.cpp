#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }

  int o = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] > p[i + 1])
      o++;
  }
  cout << o;
};