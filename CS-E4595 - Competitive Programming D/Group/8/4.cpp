#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  vector<pair<int, int>> ranges(n + 1);
  vector<unsigned long long> best(n+1);
  unsigned long long out = 0;
  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    nums[i] = a;
    best[i] = a;
    ranges[i] = {b, c};
  }
  for (int i = 1; i <= n; ++i) {
    pair<int, int> range = ranges[i];
    if (range.second == i) continue;
    else if (range.first == i) range.first++;
    for (int j = range.first; j <= range.second; ++j) {
      best[j] = max(best[j], best[i] + nums[j]);
      if (best[j] > out) out = best[j];
    }
  }
  cout << out;
}
