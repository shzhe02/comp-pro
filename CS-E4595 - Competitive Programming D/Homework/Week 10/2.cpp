#include <bits/stdc++.h>

using namespace std;

int etf(int n) {
  int res = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}

int modpow(int x, int n, int m) {
  if (n == 0) return 1;
  long long u = modpow(x,n/2,m);
  u = (u*u)%m;
  if (n%2 == 1) u = (u*x)%m;
  return u;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, m;
  cin >> a >> m;
  int out = modpow(a, etf(m) - 1, m);
  if (gcd(a, m) == 1) cout << out << '\n';
  else cout << -1 << '\n';
}
