#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> graph(n);
  vector<long long> queries(q);
  for (int &a : graph) {
    cin >> a;
    a--;
  }
  for (long long &a : queries) {
    cin >> a;
  }
  vector<bool> visited(n);
  // === DFS ===
  long long longest = *max_element(queries.begin(), queries.end());
  int curr = 0;
  vector<int> path;
  while (!visited[curr] && path.size() <= longest) {
    path.push_back(curr);
    visited[curr] = true;
    curr = graph[curr];
  }
  if (path.size() >= longest) {
    for (long long query : queries) {
      cout << path[query] + 1 << ' '; 
    }
    return 0;
  }
  int loopStart = 0;
  while(path[loopStart] != curr) {
    loopStart++;
  }
  int loopSize = path.size() - loopStart;
  for (long long query : queries) {
    if (query < path.size()) {
      cout << path[query] + 1 << ' ';
    } else {
      long long fitted = query - loopStart;
      fitted %= loopSize;
      fitted += loopStart;
      cout << path[fitted] + 1 << ' ';
    }
  }
  // cout << '\n';
  // cout << "loopSize: " << loopSize << '\n';
  // cout << "curr: " << curr << '\n';
  // cout << "loopStart: " << loopStart << '\n';
  // cout << "path: ";
  // for (int i : path) {
  //   cout << i << ' ';
  // }
  // cout << '\n';
}
