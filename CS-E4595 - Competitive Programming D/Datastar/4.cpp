#include <bits/stdc++.h>

using namespace std;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> net(n+1, vector<int>(m+1));
  int sum = 0;
  while (k--){
    int a, b;
    char c;
    cin >> a >> b >> c;
    if (c == 'K') {
      net[a][b] = -10;
      sum -= 10;
    }
    else {
      net[a][b] = 1;
      sum++;
    }
  }
  // finding minimum triangle sum
  int bestMin = numeric_limits<int>::max();
  vector<vector<int>> cumSumU(n+1, vector<int>(m+1));
  vector<vector<int>> cumSumD(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = i; k >= 1; --k) {
        int offset = (i - k) / 2;
        for (int l = j - offset; l <= j + offset; ++l) {
          if (l >= 1 && l <= m) {
            cumSumU[i][j] += net[k][l];
          }
        }
      }
      for (int k = i; k >= 1; --k) {
        int offset = (k - i) / 2;
        for (int l = j - offset; l <= j + offset; ++l) {
          if (l >= 1 && l <= m) {
            cumSumD[i][j] += net[k][l];
          }
        }
      }
      bestMin = min(bestMin, min(cumSumU[i][j], cumSumD[i][j]));
    }
  }
  cout << sum - bestMin;
}
