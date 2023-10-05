#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> roads(n + 1);
  vector<set<int>> snow(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    roads[a].insert(b);
    roads[b].insert(a);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!roads[i].count(j) && i != j) {
        snow[i].insert(j);
      }
    }
  }
  set<int> visited;
  pair<int, bool> onSnow = {0, false}; // has he already switched? int holds where
  // === dfs ===
  stack<int> path;
  path.push(1);
  while (visited.size() != n || path.empty()) { // start with roads
    
  }
  // === debug ===
  // cout << "roads:" << '\n';
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " : ";
  //   for (auto j : roads[i]) {
  //     cout << j << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << "snow: " << '\n';
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " : ";
  //   for (auto j : snow[i]) {
  //     cout << j << ' ';
  //   }
  //   cout << '\n';
  // }
}
