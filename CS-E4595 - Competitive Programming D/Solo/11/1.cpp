#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

unsigned long long lcm(int a, int b) {
  unsigned long long out = a;
  out *= b;
  out /= gcd(a, b);
  return out;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, n) / a << '\n';
  }
}
