#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// input
// 3 1 2 3

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // must be sorted first
  sort(a.begin(), a.end());

  do {
    cout << "{";
    for (int i : a) {
      cout << " " << i;
    }
    cout << " }\n";
  } while (next_permutation(a.begin(), a.end()));
};