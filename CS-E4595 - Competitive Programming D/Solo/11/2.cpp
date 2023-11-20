#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int factorial(int n) {
  if (n == 0) return 1;
  int res = 1;
  for (int i = 2; i <= n; ++i) res = (res * i) % MOD;
  return res;
}

int nCr(int n, int r) {
  return factorial(n) / ((unsigned long long) factorial(r) * factorial(n - r) % MOD);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  unsigned long long count = 0;
  for (int i = a; i <= b; ++i) {
    int ncr = nCr(n, i);
    count += ncr;
    count %= MOD;
  }
  cout << count;
}
