#include <bits/stdc++.h>

using namespace std;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int n, k;
  cin >> n >> k;
  int count = 0;
  string pattern = "";
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      pattern += '0';
      continue;
    }
    int len = 1;
    bool found = false;
    while (len <= n / k) {
      string substring = "";
      int j;
      for (j = 1; j <= len; ++j) {
        substring += pattern[i - j];
      }
      j++;
      while (i - j >= 0 && pattern[i - j] == substring[j % len]) {
        j++;
      }
      if (j / len >= k) {
        count++;
        pattern += '1';
        found = true;
        break;
      }
      len++;
    }
    if (!found) {
      pattern += '0';
    }
    cout << pattern << '\n';
  }
  cout << count;
}
