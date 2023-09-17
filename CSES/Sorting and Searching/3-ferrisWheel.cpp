#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, limit;
  cin >> n >> limit;
  vector<int> children;
  int rcursor = n - 1;
  while (n--) {
    int child;
    cin >> child;
    children.push_back(child);
  }
  sort(children.begin(), children.end());
  int lcursor = 0;
  int gondolas = 0;
  while (lcursor <= rcursor) {
    int heavy = children[rcursor];
    int light = children[lcursor];
    if (heavy + light <= limit) {
      gondolas++;
      lcursor++;
      rcursor--;
    } else {
      rcursor--;
      gondolas++;
    }
  }
  cout << gondolas;
}
