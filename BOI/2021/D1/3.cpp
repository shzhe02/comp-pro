#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int k;
  cin >> k;
  vector<vector<int>> guards(k);
  for (auto &a : guards) {
    int corners;
    cin >> corners;
    while (corners--) {
      int corner;
      cin >> corner;
      a.push_back(corner);
    }
  }
  vector<vector<bool>> visited(n); // row is node, col is time
  // === Debug ===
  // cout << "graph:" << '\n';
  // for (int i = 0; i < n; ++i) {
  //   cout << i << ": {";
  //   for (auto j : adj[i]) {
  //     cout << j << ", ";
  //   }
  //   cout << "}\n";
  // }
  // cout << "guards:" << '\n';
  // for (auto a : guards) {
  //   for (auto i : a) {
  //     cout << i << ' ';
  //   }
  //   cout << '\n';
  // }
}
