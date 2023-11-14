#include <bits/stdc++.h>

using namespace std;

long long cross(pair<long long, long long> start, pair<long long, long long> end, pair<long long, long long> point) {
  pair<long long, long long> a = {point.first - start.first, point.second - start.second};
  pair<long long, long long> b = {point.first - end.first, point.second - end.second};
  return a.first * b.second - b.first * a.second;
}

bool intersect(pair<long long, long long> a1, pair<long long, long long> a2, pair<long long, long long> b1, pair<long long, long long> b2) {
  if (cross(a1, a2, b1) > 0 && cross(a1, a2, b2) < 0) {
    return true;
  } else if (cross(a1, a2, b1) < 0 && cross(a1, a2, b2) > 0) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> pts(n);
  for (auto &a : pts) cin >> a.first >> a.second;
  pair<long long, long long> end = {numeric_limits<int>::max(), 7LL + numeric_limits<int>::max()};
  // cout << "end1: " << end.first << ", end2: " << end.second << '\n';
  while (m--) {
    pair<long long, long long> point;
    cin >> point.first >> point.second;
    int j = n - 1;
    int count = 0;
    bool boundary = false;
    for (int i = 0; i < n; ++i) {
      if (!cross(pts[j], pts[i], point)) {
        cout << "BOUNDARY" << '\n';
        boundary = true;
        break;
      }
      if (intersect(point, end, pts[j], pts[i])) {
        count++;
      }
      j = i;
    }
    if (boundary) {
      continue;
    }
    if (count % 2) {
      cout << "INSIDE" << '\n';
    } else {
      cout << "OUTSIDE" << '\n';
    }
    // cout << "count: " << count << '\n';
  }
}
