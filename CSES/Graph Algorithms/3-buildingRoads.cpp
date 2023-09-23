#include <bits/stdc++.h>

using namespace std;

int rep(int in, vector<int> &parent) {
  while (parent[in]) {
    in = parent[in];
  }
  return in;
}

bool same(int a, int b, vector<int> &parent) {
  return rep(a, parent) == rep(b, parent);
}

void unite(int a, int b, vector<int> &parent, vector<int> &size) {
  a = rep(a, parent);
  b = rep(b, parent);
  if (a == b) return;
  if (size[a] < size[b]) {
    int temp = a;
    a = b;
    b = temp;
  }
  size[a] += size[b];
  parent[b] = a;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> parent(n + 1);
  vector<int> size(n + 1, 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    unite(a, b, parent, size);
  }
  vector<int> newRoads;
  int top = rep(1, parent);
  for (int i = 1; i <= n; ++i) {
    if (!parent[i] && i != top) {
      newRoads.push_back(i);
    }
  }
  cout << newRoads.size() << '\n';
  for (int road : newRoads) cout << top << ' ' << road << '\n';
}
