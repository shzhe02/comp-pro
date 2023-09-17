#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int b;
    cin >> b;
  }
  int i = 1;
  for (int j = 0; j < 30; ++j) {
    if (i > 1000000) {
      cout << 0 << ' ';
    } else {
      cout << i << ' ';
      i *= 2;
    }
  }
}
