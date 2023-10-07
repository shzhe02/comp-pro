#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

signed main() {
  int i = 3;
  int prompt;
  cout << "buf[" << i << ']' << '\n';
  cin >> prompt;
  while (prompt > 0) {
    i = i * 2 + 1;
    cout << "buf[" << i << ']' << '\n';
    cin >> prompt;
  }
  int l = i / 2 + 1;
  int r = i;
  while (l < r) {
    int mid = (l + r) / 2;
    cout << "buf[" << mid << ']' << '\n';
    cin >> prompt;
    if (prompt == 0) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << "strlen(buf) = " << l << '\n';
}
