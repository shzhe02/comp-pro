#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> nums(n);
  long best = numeric_limits<long>::min();
  for (auto &a : nums) {
    cin >> a;
  } 
  long localBest = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] > localBest) {
      localBest = max(nums[i], localBest + nums[i]);
    } else {
      localBest += nums[i];
    }
    best = max(best, localBest);
  }
  best = max(best, localBest);
  cout << best;
}
