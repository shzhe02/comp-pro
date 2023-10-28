#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>(n + 1));
  vector<vector<int>> distance(n + 1, vector<int>(n + 1));
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) distance[i][j] = 0;
      else if (adj[i][j]) distance[i][j] = adj[i][j];
      else distance[i][j] = 1e8;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }
  int bestNode;
  int minDistance = numeric_limits<int>::max();
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = 1; j <= n; ++j) {
      sum += distance[i][j];
    }
    if (sum < minDistance) {
      minDistance = sum;
      bestNode = i;
    }
  }
  cout << bestNode;
}
