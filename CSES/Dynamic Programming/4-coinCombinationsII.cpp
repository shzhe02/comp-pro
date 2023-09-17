#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> coins(n);
  vector<int> count(target + 1);
  for (auto &a : coins) {
    cin >> a;
  }
  count[0] = 1;
  for (int coin : coins) {
    for (int i = 1; i <= target; ++i) {
      if (i - coin >= 0) {
        count[i] += count[i - coin];
        count[i] %= 1000000007;
      }
    }
  }
  cout << count[target];
}