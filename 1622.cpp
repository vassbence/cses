#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  vector<string> p;
  p.push_back(s);
  while (next_permutation(s.begin(), s.end())) {
    p.push_back(s);
  }

  cout << p.size() << '\n';

  for (const string& e : p) {
    cout << e << '\n';
  }
};