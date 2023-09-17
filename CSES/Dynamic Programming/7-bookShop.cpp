#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, money;
  cin >> n >> money;
  vector<pair<int, int>> books(n); // (pages, price)
  vector<int> best(money + 1);
  for (auto &a : books) {
    cin >> a.second;
  }
  for (auto &a : books) {
    cin >> a.first;
  }
  for (auto book : books) {
    for (int i = money; i > 0; --i) {
      if (i - book.second >= 0) {
        best[i] = max(best[i], best[i - book.second] + book.first);
      }
    }
  }
  cout << best[money];
}
