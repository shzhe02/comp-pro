#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<float> q(n);
  for (auto &a : q) {
    cin >> a;
  }
  sort(q.begin(), q.end(), greater<float>());
  float best = 0;
  for (int i = k; i <= n; i += 2) {
    float curr = 0;
    for (int j = 0; j <= (i - k) / 2; ++j) { // given j potentially wrong answers
      string perm(i - j, '^');
      string wrong(j, '*');
      wrong += perm;
      float cuml = 1;
      do {
        for (int m = 0; m < wrong.size(); ++m) {
          if (wrong[m] == '^') { // it's correct
            cuml *= q[m];
          } else {
            cuml *= 1.0 - q[m];
          }
        }
        curr += cuml;
        cuml = 1;
      } while (next_permutation(wrong.begin(), wrong.end()));
    }
    best = max(best, curr);
  }
  cout << best;
}
