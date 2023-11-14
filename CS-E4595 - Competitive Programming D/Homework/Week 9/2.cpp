#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int v = 0;
  int h = 0;
  unsigned long long count = 0;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      count += h;
      v++;
    } else if (y1 == y2) {
      count += v;
      h++;
    }
  }
  cout << count;
}
