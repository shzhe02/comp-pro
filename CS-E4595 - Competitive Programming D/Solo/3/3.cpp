#include <bits/stdc++.h>
#include <limits>

using namespace std;

long solve(int n, vector<int> sectors, int fixed) {
  vector<vector<long>> dp(3, vector<long>(n, numeric_limits<long>::min())); // black, green, red
  long val;
  switch (fixed) {
    case 0:
    val = sectors[0];
    break;
    case 1:
    val = 0;
    break;
    case 2:
    val = -sectors[0];
    break;
  }
  dp[fixed][0] = val;
  for (int i = 1; i < n; ++i) {
    dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + sectors[i];
    dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]);
    long check = max(dp[0][i - 1], dp[1][i - 1]);
    if (check != numeric_limits<long>::min()) {
      dp[2][i] = check - sectors[i];
    }
  }
  long best = numeric_limits<long>::min();
  for (int i = 0; i < 3; ++i) {
    if (i != fixed) {
      best = max(best, dp[i][n - 1]);
    }
  }
  return best;
}

int main() {
  int n;
  cin >> n;
  vector<int> sectors(n);
  for (auto &a : sectors) {
    cin >> a;
  }
  long best = numeric_limits<long>::min();
  for (int i = 0; i < 3; ++i) {
    best = max(best, solve(n, sectors, i));
  }
  cout << best;
}
