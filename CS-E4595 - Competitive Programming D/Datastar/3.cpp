#include <bits/stdc++.h>

using namespace std;

unsigned long long check(int curr, vector<vector<int>> &adj, vector<int> &plows) {
  unsigned long long sum = 0;
  for (int lower : adj[curr]) {
    sum += check(lower, adj, plows);
  }
  return max(sum, (unsigned long long) plows[curr]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n+1);
  vector<int> plows(n+1);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b); // there is a path from a to b
  }
  for (int i = 1; i <= n; ++i) {
    cin >> plows[i];
  }
  cout << check(1, adj, plows);
}
