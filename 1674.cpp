#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
vector<int> adj[N];
// not needed because we know this is a tree
// bool visited[N];
int o[N];

void dfs(int n) {
  //   if (visited[n]) {
  //     return;
  //   }
  //   visited[n] = true;

  for (auto an : adj[n]) {
    dfs(an);
    o[n] += 1 + o[an];
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int b;
    cin >> b;
    adj[b].push_back(i);
  }

  dfs(1);

  for (int i = 1; i <= n; i++) {
    cout << o[i] << " ";
  };
};