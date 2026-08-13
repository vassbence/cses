#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
  int n;
  cin >> n;

  // [ [start, end, pay], ... ]
  vector<array<int, 3>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i][0] >> p[i][1] >> p[i][2];
  }

  // we need to be sorted for binary search. and we will be binary searchin the
  // end of each project so sort by that
  sort(p.begin(), p.end(),
       [](const auto &a, const auto &b) { return a[1] < b[1]; });

  // represents the max pay we can get from the first i projects
  // the choice at every project is that we either:
  // - don't take it, so we have dp[i-1] money
  // - take it, we get it's p[i-1][2] reward but we don't add that reward to
  // dp[i-1] but to dp[index_of_last_compatible_project] because projects can
  // overlap and we have to find the last one that would work with the one we
  // are curreintly deciding on
  vector<ll> dp(n + 1);

  for (int i = 1; i <= n; i++) {
    // from start of p to i finds project whose end date is smaller than the
    // current projects start date
    // lower_bound(begin, end, value, comparator)
    auto it = lower_bound(p.begin(), p.begin() + i - 1, p[i - 1][0],
                          [](const auto &e, auto v) { return e[1] < v; });
    // we either don't take the current project or take it but then re-work our
    // schedule if needed (possibly dropping a project or two if they would
    // clash with the current one we are looking at)
    dp[i] = max(dp[i - 1], p[i - 1][2] + dp[distance(p.begin(), it)]);
  }

  cout << dp[n];
};