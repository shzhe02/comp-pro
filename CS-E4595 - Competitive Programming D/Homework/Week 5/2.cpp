#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> visited(n);
  vector<vector<int>> adj(n);
  stack<int> out;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
  }
  for (int i = 0; i < n; ++i) {
    if (visited[i]) {
      continue;
    }
    vector<bool> inLine(n);
    stack<int> line;
    line.push(i);
    inLine[i] = true;
    visited[i] = true;
    while (!line.empty()) {
      int look = -1;
      for (int next : adj[line.top()]) {
        if (inLine[next]) {
          cout << "IMPOSSIBLE";
          return 0;
        }
        if (look < 0 && !visited[next]){
          look = next;
        }
      }
      if (look >= 0) {
        line.push(look);
        inLine[look] = true;
        visited[look] = true;
      } else { // found a dead end
        out.push(line.top());
        inLine[line.top()] = false;
        line.pop();
      }
    }
  }
  while (!out.empty()) {
    cout << out.top() + 1 << ' ';
    out.pop();
  }
}
