#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> graph(n + 1, vector<vector<int>>(n + 1)); // for each node: [start][end] = weight
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b].push_back(c);
    graph[b][a].push_back(0);
  }
  int threshold = 1e9;
  unsigned long long flow = 0;
  while (threshold) {
    stack<int> dfs;
    vector<bool> visited(n + 1);
    dfs.push(1);
    visited[1] = true;
    int bot = numeric_limits<int>::max();
    while (!dfs.empty()) {
      int curr = dfs.top();
      bool pushed = false;
      for (int i = 1; i <= n; ++i) {
        if (visited[i] || graph[curr][i].empty()) continue;
        for (int w : graph[curr][i]) {
          if (w >= threshold) {
            bot = min(bot, w);
            dfs.push(i);
            visited[i] = true;
            pushed = true;
            break;
          }
        }
        if (pushed) break;
      }
      if (dfs.top() == n) { // path from 1 to n was found
        int last = n;
        flow += bot;
        dfs.pop();
        while (!dfs.empty()) {
          int curr = dfs.top();
          for (int i = 0; i < graph[curr][last].size(); ++i) {
            if (graph[curr][last][i] >= bot) {
              graph[curr][last][i] -= bot;
              graph[last][curr][i] += bot;
              break;
            }
          }
          last = curr;
          dfs.pop();
        }
        // reset dfs
        dfs.push(1);
        fill(visited.begin() + 1, visited.end(), false);
      } else if (!pushed) {
        dfs.pop();
      }
    }
    threshold >>= 1;
  }
  cout << flow;
}
