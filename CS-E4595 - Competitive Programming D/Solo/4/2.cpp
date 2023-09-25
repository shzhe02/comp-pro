#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<long>> prefix(n, vector<long>(n));
  for (int i = 0; i < n; ++i) { // row
    string treeline;
    cin >> treeline;
    for (int j = 0; j < n; ++j) { // col
      long sum = 0;
      if (i > 0) {
        sum += prefix[i - 1][j];
      }
      if (j > 0) {
        sum += prefix[i][j - 1];
        if (i > 0) {
          sum -= prefix[i - 1][j - 1];
        }
      }
      prefix[i][j] = sum + (treeline[j] == '*');
    }
  }
  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;
    long big = prefix[y2][x2];
    if (x1 > 0) {
      big -= prefix[y2][x1 - 1];
    }
    if (y1 > 0) {
      big -= prefix[y1 - 1][x2];
    }
    if (x1 > 0 && y1 > 0) {
      big += prefix[y1 - 1][x1 - 1];
    }
    cout << big << '\n';
  }
}
