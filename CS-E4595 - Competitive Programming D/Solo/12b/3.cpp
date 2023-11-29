#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  cin >> num;
  vector<int> dp(num + 1);
  dp[0] = 1;
  for (int i = 0; i <= num; ++i) {
    for (int j = 1; j <= 6 && i - j >= 0; ++j) {
      dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }
  cout << dp[num];
}
