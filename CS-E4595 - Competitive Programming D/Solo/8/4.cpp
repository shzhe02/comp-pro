#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  bitset<3500> adj[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      adj[i][j] = (c - '0');
    }
  }
  unsigned long long count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (adj[i][j] == 1 && i != j) {
        count += (adj[i] & adj[j]).count();
      }
    }
  }
 
  cout << count / 6;
}