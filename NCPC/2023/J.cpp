#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> items(n);
  for (auto &a : items) {
    cin >> a;
  }
  sort(items.begin(), items.end());
  int heaviest = items[n - 1];
  if (n <= m) {
    cout << heaviest;
    return 0;
  }
  int l = 0;
  int r = ((n - m) << 1) - 1;
  while (l < r) {
    heaviest = max(heaviest, items[l] + items[r]);
    l++; r--;
  }
  cout << heaviest;
}
