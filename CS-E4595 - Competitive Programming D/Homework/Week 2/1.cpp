#include <bits/stdc++.h>

using namespace std;

const unsigned int m = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> mem(n+1);
  mem[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) {
        mem[i] += mem[i-j];
        mem[i] %= m;
      }
    }
  }
  cout << mem[n];
}
