#include <bits/stdc++.h>

using namespace std;

// for an array a there are 2^n subsets
// it's 2^n because you have n elements and two independent choices for each
// (include or not include)
// so it's just 2 * 2 * 2 ... n times == 2^n
// in c++ thats either pow(2,n) or because it's 2
// we can use bit manipulation and shift 1 to the left n times
// 1 << n == 2^n

// input
// 3 1 2 3

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> c;
  for (int i = 0; i < 1 << n; i++) {
    c.clear();

    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        c.push_back(a[j]);
      }
    }

    cout << "{";
    for (int i : c) {
      cout << " " << i;
    }
    cout << " }\n";
  }
};