#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  vector<vector<int>> distances(a.length() + 1, vector<int>(b.length() + 1));
  int diag = 1;
  for (int i = 1; i <= a.length(); ++i) distances[i][0] = i;
  for (int i = 1; i <= b.length(); ++i) distances[0][i] = i;
  
  for (int i = 1; i <= a.length(); ++i) { // i is row, j is col
    for (int j = 1; j <= b.length(); ++j) {
      int best = numeric_limits<int>::max();
      best = min(best, distances[i - 1][j] + 1);
      best = min(best, distances[i][j - 1] + 1);
      best = min(best, distances[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
      distances[i][j] = best;
    }
  }
  cout << distances[a.length()][b.length()];
}
