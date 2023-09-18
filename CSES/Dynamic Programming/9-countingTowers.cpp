#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> tests(n);
  for (int &a : tests) {
    cin >> a;
  }
  int max = *max_element(tests.begin(), tests.end());
  vector<vector<long long>> towers(2, vector<long long>(max + 1)); 
  // two rows, 1st row for case where base is fused, 2nd row for where base is split.
  towers[0][1] = 1;
  towers[1][1] = 1;
  for (int i = 2; i <= max; ++i) {
    // 1st case: fused base
    towers[0][i] = 2 * towers[0][i - 1] + towers[1][i - 1];
    towers[0][i] %= 1000000007;
    // 2nd case: split base
    towers[1][i] = 4 * towers[1][i - 1] + towers[0][i - 1];
    towers[1][i] %= 1000000007;
  }
  for (int test : tests) {
    cout << (towers[0][test] + towers[1][test]) % 1000000007 << '\n';
  }
}
