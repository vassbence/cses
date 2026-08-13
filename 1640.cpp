#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  // key: number, value: index in input array
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;

    // if the difference of goal and the current element is already in the map
    // then we got a pair and we just need to print it and we are done
    if (m.count(x - c)) {
      // +1 because printing request 1 based indexing
      cout << m[x - c] + 1 << ' ' << i + 1 << '\n';
      return 0;
    }

    // otherwise we record the element + it's index in the array so later we can
    // have O(1) lookup
    m[c] = i;
  }

  cout << "IMPOSSIBLE";
};