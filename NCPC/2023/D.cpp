#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int>> dice(3, vector<int>(6));
  for (auto &a : dice) {
    for (auto &b : a) {
      cin >> b;
    }
  }
  for (int i = 0; i < 3; ++i) sort(dice[i].begin(), dice[i].end());
  int bestTop = 0;
  int bestDice = 0;
  for (int i = 0; i < 3; ++i) {
    if (dice[i][3] > bestTop) {
      bestTop = dice[i][3];
      bestDice = i;
    }
  }
  cout << "bestTop: " << bestTop << ", bestDice: " << bestDice << '\n';
  int maxBot = 0;
  for (int i = 0; i < 3; ++i) {
    if (i != bestDice) {
      maxBot = max(maxBot, dice[i][2]);
    }
  }
  cout << "maxBot: " << maxBot << '\n';
  if (bestTop > maxBot) {
    cout << bestDice + 1;
  } else {
    cout << "No dice";
  }
}
