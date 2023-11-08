#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  string t;
  cin >> s >> t;
  int sCursor = 0;
  int tCursor = 0;
  if (s.size() < t.size()) {
    cout << "No";
    return 0;
  }
  // s must be longer or equal to t
  while (tCursor < t.size() && sCursor < s.size()) {
    if (s[sCursor] == t[tCursor]) {
      tCursor++;
      sCursor++;
    } else {
      sCursor++;
    }
  }
  if (tCursor == t.size() && sCursor <= s.size()) cout << "Yes";
  else cout << "No";
}
