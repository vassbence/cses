#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (long long int k = 1; k < n + 1; k++) {
    // total number of possible placements (how to select 2 squares from a board
    // of k x k)
    long long int t = (k * k * (k * k - 1)) / 2;

    // possible attacking positions, which are either 2 x 3 or 3 x 2 rectangles.
    // in each of these rectangles exactly 2 positions are attacking positions
    // (one "layout" they face eachother, and there are 2 distinct positions
    // because we can swap the pieces)

    // to calculate how many 2 x 3 and 3 x 2 rectangles there are think of it
    // this way: how many starting positions can a 2 height rect have in k? it
    // can start 1, 2, ..., k-1; 3 wide can start at 1, 2, ..., k-2 so there are
    // k-1 * k-2 possibilites
    long long int a = (k - 1) * (k - 2) * 2 + (k - 2) * (k - 1) * 2;

    cout << t - a << '\n';
  }
};