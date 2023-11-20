#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, y;
  cin >> n >> y;
  int smallest;
  cin >> smallest;
  for (int i = 1; i < n; ++i) {
    int next;
    cin >> next;
    smallest = gcd(smallest, next);
  }
  if (y % smallest) cout << "No";
  else cout << "Yes";
}
