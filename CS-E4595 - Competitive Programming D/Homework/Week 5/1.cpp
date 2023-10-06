#include <bits/stdc++.h>
#include <limits>
#include <queue>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  while (m--) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    adj[a].push_back({b, w});
  }
  vector<int> distance(n);
  priority_queue<pair<int, int>> q; // distance, node
  vector<bool> processed(n);
  q.push({0, 0});
  for (int i = 0; i < n; ++i) distance[i] = numeric_limits<int>::max();
  distance[0] = 0;
  while (!q.empty()) {
    int curr = q.top().second; q.pop();
    if (processed[curr]) continue;
    processed[curr] = true;
    for (auto next : adj[curr]) {
      int other = next.first, weight = next.second;
      if (distance[curr] + weight < distance[other]) { // if going from this node to the other node is faster than the other node's original distance
        distance[other] = distance[curr] + weight;
        q.push({-distance[other], other}); // process nodes adjacent to the next node
      }
    }
  }
  for (int dist : distance) {
    cout << dist << ' ';
  }
}
