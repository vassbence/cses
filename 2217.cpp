#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  if (!(cin >> n >> m)) {
    return 0;
  }

  vector<int> p(n + 1), v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    p[v[i]] = i;
  }

  int o = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] > p[i + 1]) {
      o++;
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    int va = v[a], vb = v[b];

    if (va > 1 && p[va - 1] > p[va]) {
      o--;
    }
    if (va < n && p[va] > p[va + 1]) {
      o--;
    }
    if (vb > 1 && vb - 1 != va && p[vb - 1] > p[vb]) {
      o--;
    }
    if (vb < n && vb + 1 != va && p[vb] > p[vb + 1]) {
      o--;
    }

    swap(v[a], v[b]);
    p[va] = b;
    p[vb] = a;

    if (va > 1 && p[va - 1] > p[va]) {
      o++;
    }
    if (va < n && p[va] > p[va + 1]) {
      o++;
    }
    if (vb > 1 && vb - 1 != va && p[vb - 1] > p[vb]) {
      o++;
    }
    if (vb < n && vb + 1 != va && p[vb] > p[vb + 1]) {
      o++;
    }

    cout << o << "\n";
  }

  return 0;
}