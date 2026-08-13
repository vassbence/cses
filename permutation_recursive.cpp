#include <bits/stdc++.h>

using namespace std;

// input
// 3 1 2 3

void solve(vector<int> &a, int i) {
  if (i == (int)a.size()) {
    cout << "{";
    for (int i : a) {
      cout << " " << i;
    }
    cout << " }\n";
    return;
  }

  for (int j = i; j < (int)a.size(); j++) {
    swap(a[i], a[j]);
    solve(a, i + 1);
    swap(a[j], a[i]);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  solve(a, 0);
};