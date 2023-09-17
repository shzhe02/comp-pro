#include <iostream>

using namespace std;

void solve(int n, int start, int end, int aux) {
  if (n == 1) {
    cout << start << " " << end << "\n";
  } else {
    solve(n - 1, start, aux, end);
    cout << start << " " << end << "\n";
    solve(n - 1, aux, end, start);
  }
}

int main() {
  int n;
  cin >> n;
  int num = 2;
  for (int i = 1; i < n; i++) {
    num *= 2;
  }
  cout << num - 1 << "\n";
  solve(n, 1, 3, 2);
}

