#include <bits/stdc++.h>

using namespace std;

int main() {
  // representing the grid as a state string
  string s;

  for (int i = 0; i < 9; i++) {
    char c;
    cin >> c;
    s += c;
  }

  // bfs
  queue<pair<string, int>> q;
  unordered_set<string> v;
  q.push({s, 0});

  while (q.size()) {
    auto [cs, cc] = q.front();
    q.pop();

    if (cs == "123456789") {
      cout << cc << "\n";
      return 0;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int k = i * 3 + j;

        if (j + 1 < 3) {
          int kr = i * 3 + (j + 1);
          swap(cs[k], cs[kr]);
          if (!v.count(cs)) {
            v.insert(cs);
            q.push({cs, cc + 1});
          }
          swap(cs[k], cs[kr]);
        }

        if (i + 1 < 3) {
          int kd = (i + 1) * 3 + j;
          swap(cs[k], cs[kd]);
          if (!v.count(cs)) {
            v.insert(cs);
            q.push({cs, cc + 1});
          }
          swap(cs[k], cs[kd]);
        }
      }
    }
  }

  cout << 0 << "\n";
  return 0;
}