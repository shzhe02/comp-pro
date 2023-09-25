#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> prefix(n, vector<int>(k));
  int interest;
  cin >> interest;
  interest--;
  prefix[0][interest]++;
  for (int i = 1; i < n; ++i) {
    cin >> interest;
    interest--;
    for (int j = 0; j < k; ++j) {
      prefix[i][j] = prefix[i - 1][j];
    }
    prefix[i][interest]++;
  }
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    l--; r--; x--;
    int out = prefix[r][x];
    if (l > 0) {
      out -= prefix[l - 1][x];
    }
    cout << out << '\n';
  }
}
