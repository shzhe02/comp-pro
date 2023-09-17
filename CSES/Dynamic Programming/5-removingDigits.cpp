#include <bits/stdc++.h>

using namespace std;

vector<int> getDigits(int n) {
  int copy = n;
  vector<int> out; // non-zero digits
  while (copy) {
    int digit = copy % 10;
    if (digit > 0) {
      out.push_back(digit);
    }
    copy /= 10;
  }
  return out;
}

int main() {
  int n;
  cin >> n;
  vector<int> steps(n + 1, numeric_limits<int>::max());
  steps[n] = 0;
  for (int i = n; i > 0; --i) {
    if (steps[i] > 1000000) {
      continue;
    }
    vector<int> digits = getDigits(i);
    for (int digit : digits) {
      if (i - digit >= 0) {
        steps[i - digit] = min(steps[i] + 1, steps[i - digit]);
      } 
    }
  }
  cout << steps[0];
}
