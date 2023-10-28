#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string in;
  cin >> in;
  bool found = false;
  for (int i = 0; i < in.size() - 1; ++i) {
    // do check for len 2
    if (in[i] == in[i + 1]) {
      cout << 2; // return immediately as it is shortest possible
      return 0;
    } else if (i < in.size() - 2 && in[i] == in[i + 2]) { // do check for len 3
      found = true;
    }
  }
  if (found) {
    cout << 3;
  } else {
    cout << -1;
  }
}
