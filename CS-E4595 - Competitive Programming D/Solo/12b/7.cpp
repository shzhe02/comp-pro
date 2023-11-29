#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  } else if (n % 11 == 0) {
    cout << n / 11;
    return 0;
  } else if (n < 11) {
    cout << -1;
    return 0;
  }
  int remaining = 11 - (n % 11); // overshoot first
  int moves = (n / 11) + 1;
  if (remaining % 2) { // odd number remaining
    moves++; // overshoot further
    remaining += 11;
    moves += remaining / 2;
  } else { // even number remaining
    moves += remaining / 2;
  }
  cout << moves;
}
