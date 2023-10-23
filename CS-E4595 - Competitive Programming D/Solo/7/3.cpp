#include <bits/stdc++.h>
 
using namespace std;
 
bool dfs(vector<set<int>> &noPath, stack<int> currPath, vector<bool> &visited, int n) {
  for (int i = n; i > 0; --i) {
    if (visited[i] || noPath[currPath.top()].count(i)) continue;
    if (i == n) {
      currPath.push(n);
      cout << currPath.size() << '\n';
      vector<int> ans;
      while (!currPath.empty()) {
        ans.push_back(currPath.top());
        currPath.pop();
      }
      reverse(ans.begin(), ans.end());
      for (int i : ans) {
        cout << i << ' ';
      }
      return true;
    }
    visited[i] = true;
    currPath.push(i);
    bool found = dfs(noPath, currPath, visited, n);
    if (found) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> noPath(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    noPath[a].insert(b);
    noPath[b].insert(a);
  }
  vector<bool> visited(n + 1);
  stack<int> currPath;
  currPath.push(1);
  bool found = dfs(noPath, currPath, visited, n);
  if (!found) cout << 0;
}