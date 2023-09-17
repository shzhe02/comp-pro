#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> team(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    
  }
}
