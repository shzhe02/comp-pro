#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> legend(n + 1);
  vector<int> calc(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    int master;
    cin >> master;
    if (i != master) {
      legend[master] = i;
    }
  }
  cout << '\n';
  for (int i = 0; i < q; ++i) {
    int query;
    cin >> query;
    int original = query;
    vector<bool> visited(n + 1);
    stack<int> update;
    update.push(query);
    // 0 is end of the path
    // if something has already been visited on the way down, do not update.
    bool loop = false;
    while (legend[update.top()] != 0) {
      visited[query] = true;
      query = legend[query];
      if (calc[query] > 1) {
        break;
      } else if (visited[query]) {
        loop = true;
        update.push(query);
        break;
      }
      update.push(query);
    }
    if (loop) {
      int start = update.top(); update.pop();
      int count = 1;
      vector<int> inLoop;
      inLoop.push_back(start);
      while (update.top() != start) {
        inLoop.push_back(update.top());
        update.pop();
        count++;
      }
      for (int i : inLoop) {
        calc[i] = count;
      }
      update.pop();
      query = update.top();
    }
    int bottom = calc[query];
    int offset = 1;
    while (!update.empty()) {
      int top = update.top(); update.pop();
      calc[top] = calc[bottom] + offset;
      offset++;
    }
    cout << "Calc: ";
    for (auto i: calc) {
      cout << i << ' ';
    }
    cout << '\n';
    cout << calc[original] << ' ';
  }
  cout << "\nCalc: ";
  for (auto i : calc) {
    cout << i << ' ';
  }
}
