#include <bits/stdc++.h>

using namespace std;
vector <int> adj[100001];
int g[100001];
int N, M;
bool seen[100001];
queue<int> q;
bool impossible;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int a, b;
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    adj[a].push_back(b);
  }
  for (int a=1; a<=N; a++) {
    if (! seen[a]) {
      seen[a] = true;
      g[a] = 1;
      for (auto b: adj[a]) {
        if (! seen[b]) {
          g[b] = g[a] % 3 + 1;
          q.push(b);
        }
      }
      while (!q.empty()) {
        int b = q.front();
        q.pop();
        for (auto c: adj[b]) {
          if (! seen[c]) {
          g[c] = g[b] % 3 + 1;
          q.push(c);
          } else {
            if (g[c] == g[b])
              impossible = true;
          }
        }
      }
    }
  }
  if (impossible)
    cout << "Impossible" << endl;
  else {
    cout << g[1];
    for (int i=2; i<=N; i++) {
      cout << " " << g[i];
    }
  }
  return 0;
}
