#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<int> applicants;
  priority_queue<int> apartments;
  while (n--) {
    int i;
    cin >> i;
    applicants.push(i);
  }
  while (m--) {
    int j;
    cin >> j;
    apartments.push(j);
  }
  int count = 0;
  while (!applicants.empty() && !apartments.empty()) {
    int ac = applicants.top();
    int ap = apartments.top();
    if (ac > ap + k) { // Apartment too small
      apartments.pop();
    } else if (ac < ap - k) { // Apartment too big
      applicants.pop();
    } else {
      count++;
      apartments.pop();
      applicants.pop();
    }
  }
  cout << count;
}
