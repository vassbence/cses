#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  map<char, int> m;
  for (const auto &c : s) {
    m[c]++;
  }

  string o = "";
  for (int i = 0; i < (int)s.size(); i++) {
    for (auto &[c, f] : m) {
      if (f > 0 && (o.empty() || c != o.back())) {
        f--;

        int mx = 0;
        for (auto [c2, f2] : m) {
          mx = max(mx, f2);
        }

        if (mx <= ((int)s.size() - i) / 2) {
          o += c;
          break;
        }

        f++;
      }
    }

    if ((int)o.size() != i + 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << o << '\n';
}