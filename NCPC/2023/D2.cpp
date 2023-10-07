#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int>> dice(3, vector<int>(6));
  for (auto &a : dice) {
    for (auto &b : a) {
      cin >> b;
    }
  }
}
