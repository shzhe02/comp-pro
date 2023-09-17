#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<bool>> map(n, vector<bool>(n)); // row, col
  vector<vector<int>> count(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char tile;
      cin >> tile;
      map[i][j] = tile == '*';
    }
  }
  if (map[0][0]) {
    cout << 0;
    return 0;
  }
  count[0][0] = 1;
  int diag = 1;
  while (diag <= n * 2 - 2) {
    for (int i = 0; i <= diag; ++i) {
      int j = diag - i; // i is row, j is col
      if (i < n && j < n && !map[i][j]) {
        int sum = 0;
        if (i - 1 >= 0) { // get top
          sum += count[i - 1][j];
        }
        if (j - 1 >= 0) {
          sum += count[i][j - 1];
        }
        count[i][j] = sum;
        count[i][j] %= 1000000007;
      }
    }
    diag++;
  }
  cout << count[n - 1][n - 1];
}
