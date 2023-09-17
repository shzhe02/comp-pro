#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> best(n - 1);
  for (auto &a : nums) {
    cin >> a;
  }
  for (int i = 1; i < n - 1; i++) {
    int top = 0;
    for (int j = i - 3; j > 0 && j >= i - 5; j--) {
      top = max(best[j], top);
    }
    best[i] = top + nums[i];
  }
  int top = 0;
  for (int i = n - 2; i > 0 && i >= n - 4 ; i--) {
    top = max(best[i], top);
  }
  cout << top;
}
