#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (auto &a : nums) cin >> a;
  unordered_map<long long, int> sumCount;
  long long count = 0;
  long long currSum = 0;
  for (int i = 0; i < n; ++i) {
    currSum += nums[i];
    if (currSum == target) count++;
    if (sumCount.find(currSum - target) != sumCount.end()) count += sumCount[currSum - target];
    sumCount[currSum]++;
  }
  cout << count;
}
