#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n;
  k = n;
  vector<int> entering;
  vector<int> leaving;
  while (n--) {
    int e, l;
    cin >> e >> l;
    entering.push_back(e);
    leaving.push_back(l);
  }
  sort(entering.begin(), entering.end());
  sort(leaving.begin(), leaving.end());
  int ecursor = 0;
  int lcursor = 0;
  int time = 0;
  int people = 0;
  int maxPeople = 0;
  while (ecursor < k && lcursor < k) {
    time = min(entering[ecursor], leaving[lcursor]);
    if (time <= entering[ecursor]) {
      people++;
      ecursor++;
    }
    if (time >= leaving[lcursor]) {
      people--;
      lcursor++;
    }
    maxPeople = max(maxPeople, people);
  }
  cout << maxPeople;
}
