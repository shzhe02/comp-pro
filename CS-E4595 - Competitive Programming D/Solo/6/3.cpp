#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> child(n + 1);
  vector<int> points(n + 1);
  vector<int> sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> points[i];
  }
  for (int i = 1; i <= n; ++i) {
    int parent;
    cin >> parent;
    child[parent].push_back(i);
  }
  stack<int> dfs;
  vector<bool> visited(n + 1);
  dfs.push(1);
  while (!dfs.empty()) {
    int top = dfs.top();
    visited[top] = true;
    int next = 0;
    for (int c : child[top]) {
      if (!visited[c]) {
        next = c;
        break;
      }
    }
    if (next == 0) { // checked all child nodes.
      int s = points[top];
      for (int c : child[top]) {
        s += sum[c];
      }
      sum[top] = s;
      dfs.pop();
    } else {
      dfs.push(next);
    }
  }
  // play the game
  int total = 0;
  int curr = 1;
  while (true) {
    total += points[curr];
    vector<pair<int, int>> scores; // sum, child
    for (auto i : child[curr]) {
      scores.push_back({sum[i], i});
    }
    sort(scores.rbegin(), scores.rend());
    curr = scores[1].second;
    if (child[curr].size() < 2) {
      total += points[curr];
      break;
    }
  }
  cout << total;
}
