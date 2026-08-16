#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, n;
  cin >> x >> n;

  // storing the position of lights
  set<int> ls{0, x};
  // storing the gaps between the lights
  multiset<int> gs{x};

  for (int i = 0; i < n; i++) {
    // position of the new light
    int p;
    cin >> p;

    // find the left and right neighbour of the new light
    auto it = ls.upper_bound(p);
    int r = *it;
    int l = *prev(it);

    // remove old gap
    gs.erase(gs.find(r - l));
    // insert new gaps
    gs.insert(p - l);
    gs.insert(r - p);

    // add the new light
    ls.insert(p);

    // print largest gap after each addition
    cout << *gs.rbegin() << (i == n - 1 ? "" : " ");
  }
  cout << "\n";
}