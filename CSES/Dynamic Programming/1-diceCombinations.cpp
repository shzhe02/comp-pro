#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> count(n+1);
  count[0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) {
        count[i] += count[i - j];
        count[i] %= 1000000007;
      }
    }
  }
  cout << count[n];
}
