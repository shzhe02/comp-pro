#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  vector<vector<int>> table(n, vector<int>(m + 1));
  for (auto &a : nums) {
    cin >> a;
  }
  if (nums[0] == 0) {
    for (int i = 1; i <= m; ++i) table[0][i] = 1;
  } else {
    table[0][nums[0]] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (nums[i] == 0) { // wildcard case, check every cell in column
      for (int j = 1; j <= m; ++j) {
        if (j - 1 >= 1) table[i][j] += table[i - 1][j - 1];
        table[i][j] %= MOD;
        table[i][j] += table[i - 1][j];
        table[i][j] %= MOD;
        if (j + 1 <= m) table[i][j] += table[i - 1][j + 1];
        table[i][j] %= MOD;
      }
    } else {
        if (nums[i] - 1 >= 1) table[i][nums[i]] += table[i - 1][nums[i] - 1];
        table[i][nums[i]] %= MOD;
        table[i][nums[i]] += table[i - 1][nums[i]];
        table[i][nums[i]] %= MOD;
        if (nums[i] + 1 <= m) table[i][nums[i]] += table[i - 1][nums[i] + 1];
        table[i][nums[i]] %= MOD;
    }
  }
  int sum = 0;
  for (int i = 1; i <= m; ++i) {
    sum += table[n - 1][i];
    sum %= MOD;
  }
  cout << sum;
}
