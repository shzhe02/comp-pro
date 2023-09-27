#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  n <<= 1;
  vector<int> nums(n);
  vector<pair<int, int>> swaps;
  for (int &a : nums) {
    cin >> a;
  } 
  for (int i = 0; i < n - 2; i += 2) {
    int num = nums[i];
    if (nums[i + 1] == num) {
      continue;
    }
    auto other = find(nums.begin() + i + 1, nums.end(), num);
    int otherPos = other - nums.begin();
    swaps.push_back({i + 1, otherPos});
    nums[otherPos] = nums[i + 1];
    nums[i + 1] = num;
  }
  cout << swaps.size() << '\n';
  for (auto swap : swaps) {
    cout << swap.first + 1 << ' ' << swap.second + 1 << '\n';
  }
}
