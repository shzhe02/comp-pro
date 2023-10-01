#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    vector<pair<int, int>> lands(3);
    for (int i = 0; i < 3; ++i) {
      int a, b;
      cin >> a >> b;
      if (a > b) {
        lands[i] = {a, b};
      } else {
        lands[i] = {b, a};
      }
    }
    sort(lands.begin(), lands.end());
    int x1 = max(lands[2].first, lands[0].first + lands[1].first);
    int y1 = max(lands[2].second + lands[1].second, lands[2].second + lands[0].second);

    int x2 = max(lands[0].first, max(lands[1].first, lands[2].first));
    int y2 = lands[0].second + lands[1].second + lands[2].second;
    cout << min(x1 * y1, x2 * y2) << '\n';
  }
}
