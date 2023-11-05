#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r1 = 0;
  int prev1 = 0;
  int r2 = 0;
  int prev2 = 0;
  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    if (a > prev1) r1 += a - prev1;
    prev1 = a;
  }
  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    if (a > prev2) r2 += a - prev2;
    prev2 = a;
  }
  cout << ((r1 < r2) ? 1 : 2);
}
