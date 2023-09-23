#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> map(n);
  vector<vector<char>> from(n, vector<char>(m));
  pair<int, int> start;
  pair<int, int> end;
  for (int i = 0; i < n; ++i) {
    string in;
    cin >> in;
    for (int j = 0; j < m; ++j) {
      if (in[j] == 'A') {
        start = {i, j};
        in[j] = '.';
      } else if (in[j] == 'B') {
        end = {i, j};
        in[j] = '.';
      }
      
    }
    map[i] = in;
  }
  // === BFS ===
  queue<pair<int, int>> next;
  next.push(start);
  while (!next.empty()) {
    auto top = next.front(); next.pop();
    int a = top.first;
    int b = top.second;
    if (map[a][b] == '#') {
      continue;
    } else if (top == end) {
      cout << "YES" << '\n';
      string out;
      pair<int, int> curr = {a, b};
      int i = curr.first;
      int j = curr.second;
      char currChar = from[i][j];
      while (currChar) {
        out += currChar;
        if (currChar == 'U') curr = {i + 1, j};
        else if (currChar == 'D') curr = {i - 1, j};
        else if (currChar == 'L') curr = {i, j + 1};
        else if (currChar == 'R') curr = {i, j - 1};
        i = curr.first;
        j = curr.second;
        currChar = from[i][j];
      }
      cout << out.size() << '\n';
      reverse(out.begin(), out.end());
      cout << out;
      return 0;
    } else {
      map[a][b] = '#';
    }
    if (a - 1 >= 0 && map[a - 1][b] == '.') {
      next.push({a - 1, b});
      from[a - 1][b] = 'U';
    }
    if (a + 1 < n && map[a + 1][b] == '.') {
      next.push({a + 1, b});
      from[a + 1][b] = 'D';
    }
    if (b - 1 >= 0 && map[a][b - 1] == '.') {
      next.push({a, b - 1});
      from[a][b - 1] = 'L';
    }
    if (b + 1 < m && map[a][b + 1] == '.') {
      next.push({a, b + 1});
      from[a][b + 1] = 'R';
    }
  }
  cout << "NO";
}