#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> pp(1, vector<int>(n + 1));
  vector<int> depth(n + 1);
  depth[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> pp[0][i];
    if (pp[0][i] == 1) depth[i] = 2;
  }
  // Precomputation
  int prev = 0;
  while (true) {
    bool empty = true;
    vector<int> next(n + 1);
    for (int i = 2; i <= n; ++i) {
      next[i] = pp[prev][pp[prev][i]];
      if (next[i]) empty = false;
      if (!depth[i] && depth[next[i]]) depth[i] = depth[next[i]] + (1 << (prev + 1)); 
    }
    if (empty) break;
    pp.push_back(next);
    prev++;
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (depth[a] > depth[b]) { // make sure b is the deeper one
      int tmp = a;
      a = b;
      b = tmp;
    }
    int diff = depth[b] - depth[a];
    while (diff) {
      int pow = 0;
      while ((1 << (pow + 1)) <= diff) {
        pow++;
      }
      b = pp[pow][b];
      diff -= (1 << pow);
    }
    while (a != b) {
      int i;
      for (i = pp.size() - 1; i > 0 && pp[i][a] == pp[i][b]; --i);
      a = pp[i][a];
      b = pp[i][b];
    }
    cout << a << '\n';
  }
}
