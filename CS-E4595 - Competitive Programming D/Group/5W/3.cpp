#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned long long n;
  cin >> n;
  queue<pair<vector<bool>, unsigned long long>> bfs;
  bfs.push({{}, 1});
  // false = add, true = mul
  while (!bfs.empty()) {
    auto top = bfs.front(); bfs.pop();
    pair<vector<bool>, unsigned long long> a;
    a.first = top.first;
    a.first.push_back(false);
    a.second = top.second + 3;
    if (a.second > )
    pair<vector<bool>, unsigned long long> b;
    b.first = top.first;
    b.first.push_back(true);
    b.second = top.second << 1;
    
  }
}
