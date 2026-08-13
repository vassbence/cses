#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> t;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    auto it = upper_bound(t.begin(), t.end(), k);

    if (it == t.end()) {
      t.push_back(k);
    } else {
      *it = k;
    }
  }

  cout << t.size();
};