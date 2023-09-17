#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define PB push_back
#define SQ(a) (a) * (a)

int calcCars(vector<int> machines, int time) {
  int carsMade = 0;
  for (auto machine : machines) {
    carsMade += time / machine;
  }
  return carsMade;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> machines;
  int carsMade = 0;
  int nCars, nMachines;
  int rtime = 1000000000;
  int ltime = 0;
  int cursor = 500000000;
  cin >> nMachines >> nCars;
  for (int i = 0; i < nMachines; ++i) {
    int machine;
    cin >> machine;
    machines.push_back(machine);
  }
  while (rtime > ltime) {
    int made = calcCars(machines, cursor);
    if (made < nCars) {
      ltime = cursor;
      cursor = (rtime + cursor) / 2;
    } else if (made > nCars) {
      rtime = cursor;
      cursor = (ltime + cursor) / 2;
    } else {
      cout << cursor;
      break;
    }
  }
}
