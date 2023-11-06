#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int mod = 1e9 + 7;
  
  int n;
  cin >> n;
  string sample;
  cin >> sample;
  int padding = n - sample.size();
  if (padding == 0) {
    cout << 0;
    return 1;
  }
  unsigned long long pow = 1;
  for (int i = 0; i < padding; ++i) pow = (pow * 26) % (mod);
  pow = pow * (padding + 1) % mod;
  // remove extra cases where sample string repeats
  
  cout << pow;
}
