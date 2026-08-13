#include <bits/stdc++.h>

using namespace std;

// move n disks from f to t with the help of h
void solve(int n, int f, int t, int h) {
  if (n == 0) {
    return;
  }

  // to place n-th disk to t we first need t to be clear and n-th to be the only
  // disk on f. so we first move n-1 from f to helper
  solve(n - 1, f, h, t);
  // then we move the nth to t
  cout << f << " " << t << "\n";
  // then we move n-1 ack from helper to t
  solve(n - 1, h, t, f);
}

int main() {
  int n;
  cin >> n;

  cout << pow(2, n) - 1 << "\n";
  solve(n, 1, 3, 2);
}