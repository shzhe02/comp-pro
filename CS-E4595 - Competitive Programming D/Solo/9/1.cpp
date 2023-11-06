#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n % 2 && m % 2) {
    cout << -1;
    return 0;
  } else if (n % 2) {
    cout << 'D';
    pair<int, int> curr = {2, 1};
    while (curr.second < m) {
      for (; curr.first < n; ++curr.first) cout << 'D';
      cout << 'R'; ++curr.second;
      for (; curr.first > 2; --curr.first) cout << 'U';
      if (curr.second < m) {
        cout << 'R'; ++curr.second;
      }
    }
    cout << 'U';
    curr.first--;
    for (int i = 0; i < m - 1; ++i) {
      cout << 'L';
    }
  } else {
    cout << 'R';
    pair<int, int> curr = {1, 2};
    while (curr.first < n) {
      for (; curr.second < m; ++curr.second) cout << 'R';
      cout << 'D'; ++curr.first;
      for (; curr.second > 2; --curr.second) cout << 'L';
      if (curr.first < n) {
        cout << 'D'; ++curr.first;
      }
    }
    cout << 'L';
    curr.second--;
    for (int i = 0; i < n - 1; ++i) {
      cout << 'U';
    }
  }
}
