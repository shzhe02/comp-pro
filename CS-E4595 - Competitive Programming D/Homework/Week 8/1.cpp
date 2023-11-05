#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    z[i] = max(0, min(z[i - x], y - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      x = i;
      y = i + z[i];
      z[i]++;
    }
  }
  for (auto i : z) {
    cout << i << ' ';
  }
}
