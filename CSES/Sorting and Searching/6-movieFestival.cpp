#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> movies(n);
  while (n--) {
    cin >> movies[n].first >> movies[n].second;
  }
  sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  int watched = 0;
  int time = 0;
  for (auto i : movies) {
    if (time <= i.first) {
      watched++;
      time = i.second;
    }
  }
  cout << watched;
}
