#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, long long>> verts(n);
  for (auto &a : verts) cin >> a.first >> a.second;
  long long area = 0;
  int j = n - 1;
  for (int i = 0; i < n; ++i) {
    auto a = verts[j];
    auto b = verts[i];
    area += (a.first * b.second) - (a.second * b.first);
    j = i;
  }
  if (area < 0) {
    cout << -area;
    return 0;
  }
  cout << area;
}
