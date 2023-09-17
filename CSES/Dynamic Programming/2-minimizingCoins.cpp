#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> best(target + 1, -1);
  vector<int> coins(n);
  for (auto &a : coins) {
    cin >> a;
    if (a <= target) {
      best[a] = 1;
    }
  }
  for (int i = 0; i <= target; ++i) {
    for (int coin : coins) {
      if (i - coin >= 0) {
        if (best[i - coin] < 0) {
          continue;
        } else if (best[i] < 0) {
          best[i] = best[i - coin] + 1;
        } else {
          best[i] = min(best[i], best[i - coin] + 1);
        }
      }
    }
  }
  cout << best[target];
}