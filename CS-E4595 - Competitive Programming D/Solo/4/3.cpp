#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, x;
  cin >> n >> x;
  vector<int> diff(n);
  vector<int> prefix(n);
  int curr;
  cin >> curr;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    diff[i] = a - curr;
    curr = a;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      prefix[i] = diff[i - 1];
    }
    prefix[i] += diff[i];
  }
  for (auto i : prefix) {
    cout << i << ' ';
  }
}
