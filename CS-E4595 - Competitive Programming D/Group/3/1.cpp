#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> coins(n);
  vector<int> holes(m);
  for (int &a : coins) {
    cin >> a;
  }
  for (int &a : holes) {
    cin >> a;
  }
  vector<int> bigHoles;
  vector<int> bigPos;
  int prev = 0;
  for (int i = 0; i < m; ++i) {
    if (holes[i] > prev) {
      int hole = holes[i];
      bigHoles.push_back(hole); // size, pos
      bigPos.push_back(i);
      prev = hole;
    }
  }
  for (int i = 0; i < n; ++i) { // for each coin
    int coin = coins[i];
    auto lower = lower_bound(bigHoles.begin(), bigHoles.end(), coin);
    if (lower == bigHoles.end()) {
      cout << m + 1 << ' ';
    } else {
      cout << bigPos[distance(bigHoles.begin(), lower)] + 1 << ' ';
    }
  }
}
