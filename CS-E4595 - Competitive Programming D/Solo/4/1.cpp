#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> nums(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum ^= a;
    nums[i] = sum;
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    int extra = 0;
    if (a > 0) {
      extra = nums[a - 1];
    }
    cout << (nums[b] ^ extra) << '\n';
  }
}