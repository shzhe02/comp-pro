#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m >= n) {
    cout << (n * (1 + n)) / 2;
    return 0;
  }
  n -= m - 1;
  int total = 0;
  int remainder = n % k;
  int chunk = n - (n % k);
  int mul = chunk / k;
  total += (mul * (k + chunk)) / 2;
  total += remainder * (mul + 1);
  total += (m - 1) * mul;
  if (remainder) {
    total += m - 1;
  }
  total += (m * (m - 1)) / 2;
  cout << total;
  return 0;
}
