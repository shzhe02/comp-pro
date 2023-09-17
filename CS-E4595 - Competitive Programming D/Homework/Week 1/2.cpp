#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> applicants(n);
  vector<int> apartments(m);
  while (n--) {
    // int i;
    // cin >> i;
    // applicants.push_back(i);
    cin >> applicants[n];
  }
  while (m--) {
    // int j;
    // cin >> j;
    // apartments.push_back(j);
    cin >> apartments[m];
  }
  sort(applicants.begin(), applicants.end());
  sort(apartments.begin(), apartments.end());
  int acCursor = applicants.size() - 1;
  int apCursor = apartments.size() - 1;
  int count = 0;
  while (acCursor >= 0 && apCursor >= 0) {
    int ac = applicants[acCursor];
    int ap = apartments[apCursor];
    if (ac > ap + k) { // Apartment too small
      acCursor--;
    } else if (ac < ap - k) { // Apartment too big
      apCursor--;
    } else {
      count++;
      apCursor--;
      acCursor--;
    }
  }
  cout << count;
}
