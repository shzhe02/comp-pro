#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

void move(vector<pair<double, double>> &a, vector<pair<double, double>> &b, int idxA) {
  //move from a to b
  b.push_back(a[idxA]);
  a.erase(a.begin() + idxA);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20);
  int n;
  cin >> n;
  vector<pair<double, double>> masts(n);
  vector<pair<double, double>> connected;
  for (auto &a : masts) cin >> a.first >> a.second;
  move(masts, connected, 0);
  double min = 0;
  // only n - 1 unconnected masts
  while (!masts.empty()) {
    // iterate through all unconnected masts and check their distance to any connected mast
    double closest = numeric_limits<double>::max();
    int cIdx;
    for (int i = 0; i < masts.size(); ++i) {
      auto currD = masts[i];
      for (int j = 0; j < connected.size(); ++j) {
        auto currC = connected[j];
        double dist = sqrt((currD.first - currC.first) * (currD.first - currC.first) + (currD.second - currC.second) * (currD.second - currC.second));
        if (dist < closest) {
          closest = dist;
          cIdx = i;
        }
      }
    }
    min = max(min, closest);
    move(masts, connected, cIdx);
  }
  cout << min;
}