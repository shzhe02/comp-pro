#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1); // other, width
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  vector<int> maxWidth(n + 1);
  maxWidth[1] = numeric_limits<int>::max();
  queue<int> nexts;
  nexts.push(1);
  while (!nexts.empty()) {
    int top = nexts.front(); nexts.pop();
    for (auto next : adj[top]) {
      int max = min(next.second, maxWidth[top]);
      if (max > maxWidth[next.first]) {
        maxWidth[next.first] = max;
        nexts.push(next.first);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    cout << maxWidth[i] << ' ';
  }
}
