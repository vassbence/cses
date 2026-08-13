#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  cin >> n;

  long long int s = n * (n + 1) / 2;

  if (s % 2 != 0) {
    cout << "NO" << '\n';
    return 0;
  } else {
    cout << "YES" << '\n';
  }

  vector<int> o1, o2;
  long long int r = s / 2;
  for (int i = n; i > 0; i--) {
    if (r >= i) {
      r -= i;
      o1.push_back(i);
    } else {
      o2.push_back(i);
    }
  }

  cout << o1.size() << '\n';
  for (int i = 0; i < (int)o1.size(); i++) {
    cout << o1[i] << " ";
  }
  cout << '\n';

  cout << o2.size() << '\n';
  for (int i = 0; i < (int)o2.size(); i++) {
    cout << o2[i] << " ";
  }
};