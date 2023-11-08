#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string c;
  cin >> c;
  int best = 0;
  int bestStart = -1;
  stack<int> pile;
  pile.push(-1);
  for (int i = 0; i < c.size(); ++i) {
    if (c[i] == '(') pile.push(i);
    else {
      if (pile.top() != -1 && c[pile.top()] == '(') {
        pile.pop();
        if (i - pile.top() > best) {
          best = i - pile.top();
          bestStart = pile.top();
        } else if (i - pile.top() == best) {
        }
      } else {
        pile.push(i);
      }
    }
  }
  cout << best << ' ' << bestStart;
    // cout << "---" << '\n';
    // cout << "inSet: " << inSet << '\n';
    // cout << "count: " << count << '\n';
    // cout << "currLen: " << currLen << '\n';
    // cout << "bestStart: " << bestStart << '\n';
    // cout << "bestEnd: " << bestEnd << '\n';
    // cout << "best: " << best << '\n';
}
