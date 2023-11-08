#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string c;
  cin >> c;
  int count = 0;
  int currLen = 0;
  int best = 0;
  int start = 0;
  bool inSet = false;
  int bestStart = -1;
  int bestEnd = -1;
  for (int i = 0; i < c.size(); ++i) {
    if (c[i] == ')') count--;
    else if (c[i] == '(') count++;
    if (count < 0) {
      count = 0;
    }
    if (!inSet && count > 0) {
      inSet = true;
      start = i;
      if (bestStart < 0) bestStart = start;
      currLen++;
    } else if (inSet && count == 0) {
      inSet = false;
      if (currLen > best) {
        best = currLen;
        bestStart = start;
        bestEnd = i;
        currLen = 0;
      }
    } else {
      currLen++;
    }
    // cout << "---" << '\n';
    // cout << "inSet: " << inSet << '\n';
    // cout << "count: " << count << '\n';
    // cout << "currLen: " << currLen << '\n';
    // cout << "bestStart: " << bestStart << '\n';
    // cout << "bestEnd: " << bestEnd << '\n';
    // cout << "best: " << best << '\n';
  }
  if (bestStart == -1) {
    cout << -1;
    return 0;
  } else if (bestEnd == -1) {
    bestEnd = c.size() - 1;
    while (c[bestEnd] == '(') bestEnd--;
    int remaining = count;
    int curr = bestStart;
    while (remaining > 0) {
      if (c[curr] == '(') {
        remaining--;
        curr++;
      }
    }
    if (bestEnd - curr <= 0) {
      cout << -1;
      return 0;
    } else {
      bestStart = curr;
    }
  }
  for (int i = bestStart; i <= bestEnd; ++i) {
    cout << c[i];
  }
}
