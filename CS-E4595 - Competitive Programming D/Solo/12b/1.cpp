#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> tubes(n); // inner, outer, idx
  vector<int> tubeOutIdx;
  for (int i = 0; i < n; ++i) {
    cin >> tubes[i].first.first;
    tubes[i].second = i+1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> tubes[i].first.second;
  }
  sort(tubes.rbegin(), tubes.rend());
  int currInner = numeric_limits<int>::max();
  int curr = 0;
  while (curr < n) {
    auto currTube = tubes[curr];
    if (currInner >= currTube.first.second) {
      tubeOutIdx.push_back(currTube.second);
      currInner = currTube.first.first;
    }
    curr++;
  }
  cout << tubeOutIdx.size() << '\n';
  for (int i = tubeOutIdx.size() - 1; i >= 0; --i) {
    cout << tubeOutIdx[i] << ' ';
  }
  // for (auto a : tubeOutIdx) {
  //   cout << a << ' ';
  // }
}
