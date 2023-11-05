#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> next(s.size());
  for (int i = 0; i < next.size(); ++i) {
    next[i] = i + 1;
  }
  int curr = 0;
  int stop = s.size() - 1;
  while (true) {
    if (isdigit(s[curr])) {
      int end = s.size();
      int cursor = next[curr];
      for (int i = 0; i < s[curr] - '0'; ++i) {
        s += s[cursor];
        cursor = next[cursor];
      }
      for (int i = end; i < s.size() - 1; ++i) {
        next.push_back(i + 1);
      }
      next.push_back(next[curr]);
      next[curr] = end;
    } else {
      cout << s[curr];
    }
    if (curr == stop) break;
    curr = next[curr];
  }
}
