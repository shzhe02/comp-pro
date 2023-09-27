#include <bits/stdc++.h>

using namespace std;

int getRep(int a, vector<int> &parents) {
  while (a != parents[a]) a = parents[a];
  return a;
}

void unite(int a, int b, vector<int> &parents, vector<int> &citizens, int increase) {
  a = getRep(a, parents);
  b = getRep(b, parents);
  if (citizens[a] < citizens[b]) {
    int temp = b;
    b = a;
    a = temp;
  }
  if (a == b) {
    citizens[a] += increase;
    return;
  }
  citizens[a] += citizens[b];
  citizens[a] += increase;
  parents[b] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> parents(m + 1, vector<int>(n));
  vector<vector<int>> citizens(m + 1, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    parents[0][i] = i;
    int citizen;
    cin >> citizen;
    citizens[0][i] = citizen;
  }
  // processing history
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < n; ++j) {
      parents[i][j] = parents[i - 1][j];
      citizens[i][j] = citizens[i - 1][j];
    }
    int a, b, increase;
    cin >> a >> b >> increase;
    a--; b--;
    unite(a, b, parents[i], citizens[i], increase);
  }
  // cout << "size:" << '\n';
  // printMatrix(size);
  // cout << "parents:" << '\n';
  // printMatrix(parents);
  // cout << "citizens:" << '\n';
  // printMatrix(citizens);
  // processing queries
  while (q--) {
    int town, year;
    cin >> town >> year;
    town--;
    int city = getRep(town, parents[year]);
    cout << citizens[year][city] << ' ';
  }
}
