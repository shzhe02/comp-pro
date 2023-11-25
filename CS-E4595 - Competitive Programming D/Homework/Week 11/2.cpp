#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &a : nums) cin >> a;
  sort(nums.begin(), nums.end());
  long long smallest = 1;
  for (int i = 0; i < n && nums[i] <= smallest; ++i) {
    smallest += nums[i];
  }
  cout << smallest;
}
