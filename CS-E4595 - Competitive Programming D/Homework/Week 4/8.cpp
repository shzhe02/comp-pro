#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> days(n);
  vector<int> best(n - 2);
  for (int &a : days) {
    cin >> a;
  }
  for (int i = 0; i < n - 2; ++i) {
    best[i] = max(days[i], days[i + 2]);
  }
  auto res = min_element(best.begin(), best.end());
  cout << distance(best.begin(), res) + 1 << ' ' << *res;
}
