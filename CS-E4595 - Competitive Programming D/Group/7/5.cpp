#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> throughput(n + 1);
  // [a][b] = flow from a to b
  vector<vector<int>> corridors(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    cin >> throughput[i];
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    corridors[a][b] = throughput[a]; // limited by next checkpoint
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
        // if already visited or no path
        if (visited[i] || corridors[curr][i] == 0) continue;
        // check if the corridor is above the threshold OR has infinite flow
        else if (corridors[curr][i] >= threshold || corridors[curr][i] < 0) {
          if (corridors[curr][i] > 0) {
            bot = min(bot, corridors[curr][i]);
          }
          dfs.push(i);
          visited[i] = true;
          pushed = true;
          break;
        }
        if (pushed) break;
      }
      if (dfs.top() == n) { // path from 1 to n was found
        int last = n;
        flow += bot;
        dfs.pop();
        while (!dfs.empty()) {
          int curr = dfs.top();
          if (corridors[curr][last] >= bot) {
            corridors[curr][last] -= bot;
            corridors[last][curr] += bot;
            break;
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
