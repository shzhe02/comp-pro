#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int size = 0;
  int count = 0;
  vector<int> digits(1);
  while (size + k + 1 <= n) {
    size += k + 1;
    count++;
    digits[0]++;
    for (int i = 0; i < digits.size(); ++i) {
      if (digits[i] == k && size < n) {
        if (i + 1 == digits.size()) {
          digits.push_back(1);
        } else {
          digits[i + 1]++;
        }
        digits[i] = 0;
        size++;
        count++;
      }
    }
  }
  cout << count;
}
