#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int awake = 0;
  int cups = 0;
  for (int i = 0; i < n; ++i) {
    char lecture;
    cin >> lecture;
    if (lecture == '0' && cups) {
      awake++;
      cups--;
    } else if (lecture == '1') {
      awake++;
      cups = 2;
    }
  }
  cout << awake;
}
