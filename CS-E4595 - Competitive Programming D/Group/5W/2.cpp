#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  // vector<int> count(3);
  // 0 = r, 1 = g, 2 = b
  int start = 0;
  for (int tier = 0; tier < n; ++tier) {
    vector<vector<int>> level(n, vector<int>(n));
    int currColor = start;
    for (int diag = 0; diag <= (n - 1) * 2; ++diag) {
      for (int i = 0; i < n; ++i) {
        int j = diag - i;
        if (i >= 0 && j >= 0 && i < n && j < n) {
          level[i][j] = currColor;
        }
      }
      currColor = (currColor + 1) % 3;
    }
    for (auto i : level) {
      for (auto j : i) {
        // count[j]++;
        switch (j) {
          case 0:
            cout << 'R';
            break;
          case 1:
            cout << 'G';
            break;
          case 2:
            cout << 'B';
            break;
        }
        cout << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
    start = (start + 1) % 3;
  }
  // cout << "count: " << '\n';
  // cout << "r: " << count[0] << ", g: " << count[1] << ", b: " << count[2] << '\n'; 
}