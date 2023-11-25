#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int e(int a, int n) {
  if (n == 0) return 1;
  unsigned long long out = e(a, n / 2);
  out = (out * out) % MOD;
  if (n % 2) out = (out * a) % MOD;
  return out;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int a, n;
    cin >> a >> n;
    cout << e(a, n) << '\n';
  }
}
