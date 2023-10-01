#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int x, y, n;
  cin >> x >> y >> n;
  if (!(n % x) || !(n % y)) {
    cout << 1;
    return 0;
  }
  int remaining = x * y - n;
  // find factors
  for (int i = 1; i <= y; ++i) {
    if (!(remaining % i) && remaining / i <= x) {
      cout << 2;
      return 0;
    } else if (!(n % i) && n / i <= x) {
      cout << 2;
      return 0;
    }
  }
  cout << 3;
}