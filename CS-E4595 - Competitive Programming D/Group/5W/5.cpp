#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> recurs(n, vector<int>(n)); // row is offset, col is recur
  vector<int> day(n);
  for (int i = 0; i < n; ++i) {
    int recur;
    cin >> recur;
    int offset = i % recur;
    recurs[offset][recur]++;
    int sum = 0;
    for (int j = 0; j <= i; j++) { // 
      recurs[][]
    }
  }
}
