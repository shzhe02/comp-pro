#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> prev(n + 1);
  vector<bool> visited(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> next;
  next.push(1);
  visited[1] = true;
  while (!next.empty()) {
    int top = next.front(); next.pop();
    if (top == n) {
      int curr = top;
      stack<int> path;
      while (curr) {
        path.push(curr);
        curr = prev[curr];
      }
      cout << path.size() << '\n';
      while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
      }
      return 0;
    }
    for (int i : adj[top]) {
      if (!visited[i]) {
        prev[i] = top;
        visited[i] = true;
        next.push(i);
      }
    }
  }
  cout << "IMPOSSIBLE";
}
