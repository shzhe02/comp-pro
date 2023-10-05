#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }
  int start = nums[0];
  int peak = 0;
  int best = 0;
  bool down = true;
  for (int i = 1; i < n; ++i) {
    if (nums[i] < nums[i - 1] && !down) { //downhill begins
      peak = nums[i - 1];
      down = true;
    } else if (nums[i] > nums[i - 1] && down) { // uphill begins
      best = max(best, peak - max(start, nums[i - 1]));
      start = nums[i - 1];
      down = false;
    }
  }
  if (down) { // if going downhill, peak is valid
    best = max(best, peak - max(start, nums[n - 1]));
  }
  cout << best;
}
