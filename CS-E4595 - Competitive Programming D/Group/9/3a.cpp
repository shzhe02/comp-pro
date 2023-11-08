#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string c;
  cin >> c;
  int start = 0;
  while (c[start == ')']) start++;
  int end = c.size() - 1;
  while (c[end == '(']) end--;
  if (start >= end) {
    cout << -1;
    return 0;
  }
  int count = 0;
  int currLen = 0;
  bool inSet = false;
  int currStart = 0;
  int bestStart = 0;
  int bestEnd = -1;
  int best = 0;
  for (int i = start; i <= end; ++i) {
    if (c[i] == '(') count++;
    else if (c[i] == ')' && count > 0) count--;
    currLen++;
    if (inSet && count == 0) { // close set
      inSet = false;
      // check if current set is best set
      if (currLen >= best) {
        best = currLen;
        bestStart = currStart;
        bestEnd = i;
      }
    } else if (!inSet && count > 0) { // found a start bracket
      inSet = true;
      currStart = i;
    } else { // currently in set
      currLen++;
    }
  }
  int last = end;
  int remaining = count;
  int newStart = currStart;
  while (remaining) {
    newStart++;
    if (c[newStart] == '(') remaining--;
  }
  if (last - newStart > best) {
    bestStart = newStart;
    bestEnd = last;
  }
    // cout << "---" << '\n';
    // cout << "inSet: " << inSet << '\n';
    // cout << "count: " << count << '\n';
    // cout << "currLen: " << currLen << '\n';
    // cout << "bestStart: " << bestStart << '\n';
    // cout << "bestEnd: " << bestEnd << '\n';
    // cout << "best: " << best << '\n';
  for (int i = bestStart; i <= bestEnd; ++i) {
    cout << c[i];
  }
}
