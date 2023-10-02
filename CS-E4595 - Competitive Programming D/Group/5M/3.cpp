#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

int count(int offset, int &num, int &done) {
  vector<int> ref;
  vector<int> counts;
  int digits = 1;
  ref.push_back(1 + offset);
  counts.push_back(1);
  while (1LL << digits <= num) {
    ref.push_back(ref[digits - 1] * 2 + (1 + counts[digits - 1]) * (1 + offset));
    counts.push_back(1LL + counts[digits - 1] * 2);
    digits++;
    cout << "digits: " << (1LL << digits) << ", num: " << num << '\n';
  }
  num -= ((1 << digits) - 1);
  cout << "num: " << num << '\n';
  if (num) {
    done += count(offset + 1, num, done);
  }
  return ref.back();
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int done = 0;
  cout << count(0, n, done);
}
