#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int MOD = 998244353;

ull factorial(vector<int> nums) {
  ull sum = nums[0] + nums[1] + nums[2];
  ull fact0 = 1;
  ull fact1 = 1;
  ull fact2 = 1;
  ull fact = 1;
  for (ull i = 2; i <= nums[0]; ++i) {
    fact = fact * i % MOD;
  }
  fact0 = fact;
  for (ull i = nums[0] + 1; i <= nums[1]; ++i) {
    if (i == 0) break;
    fact = fact * i % MOD;
  }
  fact1 = fact;
  for(ull i = nums[1] + 1; i <= nums[2]; ++i) {
    if (i == 0) break;
    fact = fact * i % MOD;
  }
  fact2 = fact;
  for (ull i = nums[2] + 1; i <= sum; ++i) {
    if (i == 0) break;
    fact = fact * i % MOD;
  }
  // cout << fact << '\n';
  // cout << fact0 << '\n';
  // cout << fact1 << '\n';
  // cout << fact2 << '\n';
  return fact / (fact1 * fact2 * fact0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> nums(3);
  cin >> nums[0] >> nums[1] >> nums[2];
  sort(nums.begin(), nums.end());
  cout << factorial(nums);
}
