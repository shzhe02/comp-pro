#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> boosts(n);
  for (int &a : boosts) {
    cin >> a;
  }
  vector<double> positions(n + 1, numeric_limits<double>::max()); //fastest time to get to n * 100m
   
    // boosted second + k
  positions[0] = 0;
  for (int i = 0; i <= n; ++i) {
    // check future states
    // 1: skips all boosts
    if (i < n) {
      positions[i + 1] = min(positions[i + 1], positions[i] + 1);
    }
    // 2: takes boost
    int boostedPos = i + boosts[i];
    if (boostedPos + k < n) { // post-boost and skip is at or before finish
      positions[boostedPos + k] = min(positions[boostedPos + k], positions[i] + 1 + k);
    } else if (boostedPos <= n) { // post-boost but over finish line during disabled period
      // how many skips before finish is crossed?
      int remaining = n - boostedPos;
      positions[n] = min(positions[n], positions[i] + 1 + remaining);
    } else { // boosts across finish
      double boostUsed = n - i;
      double boost = boosts[i];
      positions[n] = min(positions[n], boostUsed / boost + positions[i]);
    }
  }
  cout << positions[n];
}
