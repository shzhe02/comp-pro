#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> pads(n);
  for (int i = 0; i < m; ++i) {
    int pad;
    cin >> pad;
    pads[pad] = true;
  }
  int time = 0;
  int position = 0;
  while (time < k) {
    if (pads[position / 100]) {
      position += 200;
    } else {
      position += 100;
    }
    position %= n * 100;
    time++;
  }
  cout << position;
}
