#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<pair<int, int>> nums(n);
  for (int i = 0; i < n; ++i) { // val, pos
    nums[i].second = i + 1;
    cin >> nums[i].first;
  }  
  if (n < 3) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; ++i) { // fix this element
    int remaining = target - nums[i].first;
    int l = i + 1;
    int r = n - 1;
    while (l < r) {
      int currSum = nums[l].first + nums[r].first;
      if (currSum > remaining) r--;
      else if (currSum < remaining) l++;
      else { // found it
        cout << nums[i].second << ' ';
        cout << nums[l].second << ' ',
        cout << nums[r].second;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE";
}
