#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int time = 0;
  int count = 0;
  vector<pair<int, int>> movies;
  while (n--) {
    int a, b;
    cin >> a >> b;
    movies.push_back({a, b});
  }
  sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  });
  int cursor = 0;
  while (cursor < int(movies.size())) {
    if (time <= movies[cursor].first) {
      count++;
      time = movies[cursor].second;
    }
    cursor++;
  }
  cout << count;
}
