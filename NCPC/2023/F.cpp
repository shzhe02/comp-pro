#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sieve[1000] = {0};
  vector<int> primes;
  for (int i=2; i<2000; i++) {
    if (sieve[i] == 0) {
      primes.push_back(i);
      sieve[i] = 1;
      for (int j=i*2; j<2000; j+=i) {
        sieve[j] = 1;
      }
    }
  }
  int ans[61];
  int n;
  cin >> n;
  vector<int> parent(n + 1);
  vector<vector<int>> children(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    if (parent[b] > 0)
      swap(a, b);
    children[a].push_back(b);
    parent[b] = a;
  }
  ans[0] = 1;
  ans[1] = 2;
  queue<int> next;
  next.push(1);
  while (!next.empty()) {
    int curr = next.front(); next.pop();
    ans[curr] = ans[parent[curr]] * primes[curr - 1];
    for (int i : children[curr]) {
      next.push(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
}
