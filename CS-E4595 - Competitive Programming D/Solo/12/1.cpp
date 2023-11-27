#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool checkConnected(vector<int> &verts, vector<vector<int>> &adj) {
  vector<bool> visited(verts.size());
  // bfs
  stack<int> bfs;
  bfs.push(verts[0]);
  visited[0] = true;
  while (!bfs.empty()) {
    int curr = bfs.top(); bfs.pop();
    for (auto &next : adj[curr]) {
      auto finding = find(verts.begin(), verts.end(), next);
      if (finding != verts.end() && !visited[finding - verts.begin()]) {
        bfs.push(next);
        visited[finding - verts.begin()] = true;
      }
    }
  }
  bool connected = true;
  for (auto a : visited) {
    connected = connected && a;
  }
  return connected;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while (m--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    string test;
    for (int i = 0; i < (n >> 1) << 1; ++i) {
      if (i % 2) {
        test += "M";
      } else {
        test += "U";
      }
    }
    if (n % 2) test += "*";
    sort(test.begin(), test.end());
    do {
      // verify potential solution
      vector<int> teamM;
      vector<int> teamU;
      for (int i = 0; i < n; ++i) {
        if (test[i] == 'M') teamM.push_back(i+1);
        else if (test[i] == 'U') teamU.push_back(i+1);
      }
      bool works = checkConnected(teamM, adj) && checkConnected(teamU, adj);
      if (works) {
        cout << test << '\n';
        break;
      }
    } while (next_permutation(test.begin(), test.end()));
  }
}
