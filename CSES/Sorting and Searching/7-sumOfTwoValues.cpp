#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> nums;
  int pos = 1;
  while (n--) {
    int i;
    cin >> i;
    nums.push_back(pair<int, int>(i, pos));
    pos++;
  }
  sort(nums.begin(), nums.end());
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int sum = nums[l].first + nums[r].first;
    if (sum < x) { // undershot
      l++;
    } else if (sum > x) { //overshot
      r--;
    } else {
      cout << nums[l].second << ' ' << nums[r].second;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
}
