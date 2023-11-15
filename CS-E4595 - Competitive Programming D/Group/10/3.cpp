#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;

void moveL(vector<pair<ll, ll>> &a, vector<pair<ll, ll>> &b, int idxA) {
  //move from a to b
  b.push_back(a[idxA]);
  a.erase(a.begin() + idxA);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> masts(n);
  vector<pair<ll, ll>> connected;
  for (auto &a : masts) cin >> a.first >> a.second;
  moveL(masts, connected, 0);
  unsigned long long mini = numeric_limits<unsigned long long>::max();
  // only n - 1 unconnected masts
  while (!masts.empty()) {
    // iterate through all unconnected masts and check their distance to any connected mast
    unsigned long long closest = numeric_limits<unsigned long long>::max();
    int cIdx;
    for (int i = 0; i < masts.size(); ++i) {
      auto currD = masts[i];
      for (int j = 0; j < connected.size(); ++j) {
        auto currC = connected[j];
        unsigned long long dist = (currD.first - currC.first) * (currD.first - currC.first) + (currD.second - currC.second) * (currD.second - currC.second);
        if (dist < closest) {
          closest = dist;
          cIdx = i;
        }
      }
    }
    mini = min(mini, closest);
    moveL(masts, connected, cIdx);
  }
  cout << mini;
}