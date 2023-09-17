#include <bits/stdc++.h>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
  int n;
  long curr;
  cin >> n >> curr;
  long best = curr; // curr accumulates from the last best value
  for (int i = 1; i < n; ++i) {
    long elem;
    cin >> elem;
    curr = max(elem, curr + elem);
    best = max(best, curr);
  }
  cout << best;
}
