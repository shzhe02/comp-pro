#include <bits/stdc++.h>
#include <limits>
#include <numeric>
#include <vector>

#define int long long

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> particles(1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    cin >> particles[0][i];
  }
  particles[0][n] = 0; // last column is the cost
  while (n > 1) { // collapse each combination only has one element left
    vector<vector<int>> next;
    for (auto combo : particles) {
      for (int l = 0; l < combo.size() - 2; ++l) { // skip last (size) and second last
        vector<int> copy = combo;
        int a = copy[l];
        int b = copy[l + 1];
        int cost = a * b - min(a, b) * min(a, b);
        copy[l] += b;
        copy.erase(copy.begin() + l + 1);
        copy[copy.size() - 1] += cost;
        next.push_back(copy);
      }
    }
    particles = next;
    n--;
  }
  int best = numeric_limits<int>::max();
  for (auto i : particles) {
    best = min(best, i[1]);
  }
  cout << best;
}
