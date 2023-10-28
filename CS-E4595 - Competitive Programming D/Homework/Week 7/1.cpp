#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &a : nums) {
    cin >> a;
  }
  int bestCount = 0;
  int a;
  int b;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      unsigned long long product = nums[i];
      product *= nums[j];
      int count = __builtin_popcountll(product);
      if (count > bestCount) {
        bestCount = count;
        a = nums[i];
        b = nums[j];
      }
    }
  }
  cout << bestCount << '\n' << a << ' ' << b;
}
