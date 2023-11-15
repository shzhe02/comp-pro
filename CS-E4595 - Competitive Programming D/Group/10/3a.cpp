#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  ll d = numeric_limits<ll>::max();
  int n;
  cin >> n;
  vector<pair<ll, ll>> points;
  set<pair<ll, ll>> setPoints;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  sort(points.begin(), points.end());
  setPoints.insert(points[0]);
  for (int i = 1; i < n; ++i) {
    auto l = setPoints.lower_bound({min(points[i].first - d, numeric_limits<ll>::min()), points[i].second - d});
    auto r = setPoints.upper_bound({points[i].first, points[i].second + d});
    if (l == setPoints.end()) continue;
    for (auto p = l; p != r; ++p) {
      pair<ll, ll> v = *p;
      ull distance = (points[i].first - v.first) * (points[i].first - v.first);
      distance += (points[i].second - v.second) * (points[i].second - v.second);
      if (d > distance) d = distance;
    }
    setPoints.insert(points[i]);
  }
  cout << d;
}
