#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, double>> slowFactors(n); // diff, quot
  vector<int> requiredSpeed(n);
  vector<int> happiness(n);
  vector<int> happinessSpectrum(1000001);
  for (int i = 0; i < n; ++i) {
    cin >> happiness[i];
    cin >> requiredSpeed[i];
    cin >> slowFactors[i].first;
    cin >> slowFactors[i].second;
  }
  double absoluteMin = requiredSpeed[n - 1];
  if (n == 1) {
    cout << happiness[0];
    return 0;
  }
  happinessSpectrum[happiness[n - 1]]++;
  for (int i = n - 2; i >= 0; --i) {
    happinessSpectrum[happiness[i]]++;
    absoluteMin = max(double(requiredSpeed[i]), (absoluteMin + slowFactors[i].first) / (1.0 - (slowFactors[i].second / 100)));
  }
  unsigned long long absMin = ceil(absoluteMin);
  unsigned long long count = 0;
  for (int i = 1; i <= 1000000; ++i) {
    count += happinessSpectrum[i];
    if (count > (n + 1) >> 1) {
      cout << max(absMin, count);
      return 0;
    }
  }
}
