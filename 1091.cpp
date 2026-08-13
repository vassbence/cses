#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // correct but too slow (mostly likely because of erase has to move all items)
  //   vector<int> p(n);
  //   for (int i = 0; i < n; i++) {
  //     cin >> p[i];
  //   }

  //   sort(p.begin(), p.end());

  //   for (int i = 0; i < m; i++) {
  //     int ma;
  //     cin >> ma;

  //     auto it = upper_bound(p.begin(), p.end(), ma);

  //     if (it == p.begin()) {
  //       cout << -1 << '\n';
  //     } else {
  //       --it;
  //       cout << *it << '\n';
  //       p.erase(it);
  //     }
  //   }

  map<int, int> t;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    t[p]++;
  }

  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;

    auto it = t.upper_bound(p);

    if (it == t.begin()) {
      cout << -1 << '\n';
    } else {
      --it;
      cout << it->first << '\n';

      (it->second)--;
      if (it->second == 0) {
        t.erase(it);
      }
    }
  }
}