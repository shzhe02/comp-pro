#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;

#define X real()
#define Y imag()

pair<bool, ll> check(P p, P l1, P l2) {
  ll a = (conj(p - l1) * (p - l2)).Y;
  if (a == 0) {
    bool cond = p.X >= min(l1.X, l2.X) && p.X <= max(l1.X, l2.X) && p.Y >= min(l1.Y, l2.Y) && p.Y <= max(l1.Y, l2.Y);
    return {cond, a};
  }
  return {false, a};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    vector<P> points;
    for (int i = 0; i < 4; ++i) {
      int a, b;
      cin >> a >> b;
      points.push_back({a, b});
    }
    // 0, 1 & 2, 3 are the lines
    auto a = check(points[0], points[2], points[3]);
    auto b = check(points[1], points[2], points[3]);
    auto c = check(points[2], points[0], points[1]);
    auto d = check(points[3], points[0], points[1]);
    // cout << "a: " << a.second << ", b: " << b.second << ", c: " << c.second << ", d: " << d.second << ", d2: " << d.first;
    bool crossed1 = (a.second > 0 && b.second < 0) || (a.second < 0 && b.second > 0);
    bool crossed2 = (c.second > 0 && d.second < 0) || (c.second < 0 && d.second > 0);
    if (a.first || b.first || c.first || d.first || (crossed1 && crossed2)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
