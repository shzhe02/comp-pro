#include <bits/stdc++.h>
#include <queue>
 
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> map(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    string in;
    cin >> in;
    for (int j = 0; j < m; ++j) {
      map[i][j] = in[j] == '.';
    }
  }
  int rooms = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (map[i][j]) { // spot is part of an unvisited room
        rooms++;
        queue<pair<int, int>> next;
        next.push({i, j});
        while (!next.empty()) {
          auto curr = next.front();
          next.pop();
          int a = curr.first;
          int b = curr.second;
          if (!map[a][b]) {
            continue;
          }
          map[a][b] = false;
          if (a - 1 >= 0 && map[a - 1][b]) next.push({a - 1, b});
          if (a + 1 < n && map[a + 1][b]) next.push({a + 1, b});
          if (b - 1 >= 0 && map[a][b - 1]) next.push({a, b - 1});
          if (b + 1 < m && map[a][b + 1]) next.push({a, b + 1});
        }
      }
    }
  }
  cout << rooms;
}