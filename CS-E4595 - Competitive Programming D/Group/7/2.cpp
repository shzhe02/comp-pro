#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> adj(n + 1, vector<int>(n + 1));
  vector<vector<int>> depth(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> adj[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) depth[i][j] = numeric_limits<int>::max();
      else if (adj[i][j]) depth[i][j] = adj[i][j];
      else depth[i][j] = 0;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        depth[i][j] = max(depth[i][j], min(depth[i][k], depth[k][j]));
      }
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << depth[a][b] << '\n';
  }
}
