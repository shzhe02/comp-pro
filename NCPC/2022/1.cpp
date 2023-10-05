#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> alice(n);
  vector<int> bob(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    char c;
    cin >> a >> c >> b;
    if ((a + b) % 4 == 1 || (a + b) % 4 == 2) { // switch case
      alice[i] = b;
      bob[i] = a;
    } else {
      alice[i] = a;
      bob[i] = b;
    }
  }
  bool won = false;
  for (int i = 0; i < n; ++i) {
    if (alice[i] == 11 && bob[i] == 11) {
      cout << "error " << i + 1;
      return 0;
    }
    if (won && (bob[i] != bob[i - 1] || alice[i] != alice[i - 1])) {
      cout << "error " << i + 1;
      return 0;
    }
    if (alice[i] == 11 || bob[i] == 11) {
      won = true;
    }
    if (i == 0) continue;
    if (alice[i] < alice[i - 1] || bob[i] < bob[i - 1]) {
      cout << "error " << i + 1;
      return 0;
    }
  }
  cout << "ok";
}
