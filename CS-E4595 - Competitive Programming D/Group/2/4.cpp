#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> legos(n);
  while (n--) {
    int a, b;
    cin >> a >> b;
    legos[n] = {a + b, {a, b}};
  }
  sort(legos.begin(), legos.end(), [] (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first;
  });
  long ueHalf = 0;
  long maHalf = 0;
  for (int i = 0; i < legos.size(); ++i) {
    if (i > ((legos.size() + 1) / 2)) {
      ueHalf += legos[i].second.first;
    } else {
      maHalf += legos[i].second.second;
    }
  }
  cout << ueHalf - maHalf;
}
