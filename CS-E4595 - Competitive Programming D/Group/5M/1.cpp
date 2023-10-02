#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  int steps = 0;
  cin >> num;
  while (num) {
    int copy = num;
    int maxDigit = 0;
    while (copy) {
      int digit = copy % 10;
      if (digit > maxDigit) maxDigit = digit;
      copy /= 10;
    }
    num -= maxDigit;
    steps++;
  }
  cout << steps;
}
