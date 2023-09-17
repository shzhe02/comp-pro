#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> seq(n), pos(n);
  for (int &k: seq) {
    cin >> k;
    k--;
  }  
  int out = 1;
  for (int i = 0; i < n; ++i) {
    pos[seq[i]] = i;
  }
  for (int i = 1; i < n; ++i) {
    if (pos[i] < pos[i - 1]) {
      out++;
    }
  }
  cout << out;
}
