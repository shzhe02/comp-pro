#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i].first;
    nums[i].second = i;
  }
  sort(nums.begin(), nums.end());
  vector<bool> visited(n);
  int count = 0;
  for (int i = 0; i < n; ++i) {
    // visited or already in right position
    if (visited[i] || nums[i].second == i) continue;
    int size = 0;
    int j = i;
    while (!visited[j]) {
      visited[j] = true;
      j = nums[j].second;
      size++;
    }
    if (size > 0) {
      count += size - 1;
    }
  }
  cout << count;
}
