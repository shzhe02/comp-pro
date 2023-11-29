#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> graph(n+1);
  vector<int> coloring(n+1); // 1, 2, 3
  vector<bool> visited(n + 1);
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    graph[i].push_back(t);
    graph[t].push_back(i);
  }
  stack<int> bfs;
  bfs.push(1);
  visited[1] = true;
  while (!bfs.empty()) {
    vector<int> neighborColors;
    int color = 1;
    int curr = bfs.top(); bfs.pop();
    for (int next : graph[curr]) {
      if (!visited[next]) {
        bfs.push(next);
        visited[next] = true;
      } else { // check colors
        neighborColors.push_back(coloring[next]);
      }
    }
  }
}
