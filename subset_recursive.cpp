#include <bits/stdc++.h>

using namespace std;

// this recursive solution basically goes depth first on the "include current
// element in subset" path and when reaches the end (i == a.size()) then each of
// those recursive fns return and their parent goes to the "do not include
// current element in subset" path and so we build a tree.

// input
// 3 1 2 3

void solve(vector<int> &a, vector<int> &c, int i) {
  if (i == (int)a.size()) {
    cout << "{";
    for (int i : c) {
      cout << " " << i;
    }
    cout << " }\n";
    return;
  }

  c.push_back(a[i]);
  solve(a, c, i + 1);

  c.pop_back();
  solve(a, c, i + 1);
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> c;

  solve(a, c, 0);
};