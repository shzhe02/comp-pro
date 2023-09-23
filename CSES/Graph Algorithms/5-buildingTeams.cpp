#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bool> colors(n + 1);
  vector<bool> visited(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> next;
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) {
      continue;
    } else {
      next.push(i);
    }
    while (!next.empty()) {
      int top = next.front(); next.pop();
      visited[top] = true;
      for (int a : adj[top]) {
        if (!visited[a]) {
          colors[a] = !colors[top];
          next.push(a);
        } else if (colors[top] == colors[a]) {
          cout << "IMPOSSIBLE";
          return 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << colors[i] + 1 << ' ';
  }
}
