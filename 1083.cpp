#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> s;

  for (int i = 0; i < n - 1; i++) {
    int j;
    cin >> j;
    s.insert(j);
  }

  for (int i = 1; i < n + 1; i++) {
    if (!s.count(i)) {
      cout << i << '\n';
      break;
    }
  }
};