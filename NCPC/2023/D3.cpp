#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> d1, vector<int> d2) {
  int tie = 0;
  int d1Bigger = 0;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (d1[i] > d2[j]) d1Bigger++;
      if (d1[i] == d2[j]) tie++;
    }
  }
  
  return (d1Bigger >= (36 - d1Bigger - tie)) && tie != 36;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int>> dice(3, vector<int>(6));
  for (auto &a : dice) {
    for (auto &b : a) {
      cin >> b;
    }
  }
  bool o1 = compare(dice[0], dice[1]);
  bool o2 = compare(dice[0], dice[2]);
  bool o3 = compare(dice[1], dice[0]);
  bool o5 = compare(dice[1], dice[2]);
  bool o4 = compare(dice[2], dice[0]);
  bool o6 = compare(dice[2], dice[1]);
  
  if (o1 && o2) {
    cout << 1 << endl;
  } else {
    if (o3 && o5)
      cout << 2 << endl;
    else {
      if (o4 && o6)
        cout << 3 << endl;
      else
        cout << "No dice" << endl;
    }
  }

}
