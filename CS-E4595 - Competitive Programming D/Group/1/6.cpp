#include <bits/stdc++.h>
#include <vector>

using namespace std;

long apple(vector<int> list, long total, long subtotal, int index) {
  if (index == 0) {
    return abs(total - subtotal * 2);
  }
  return min(
    apple(list, total, subtotal + list[index], index - 1),
    apple(list, total, subtotal, index - 1)
  );
}

int main() {
  int n;
  cin >> n;
  vector<int> in(n);
  long sum = 0;
  for (auto &a : in) {
    cin >> a;
    sum += a;
  }
  cout << apple(in, sum, 0, n - 1);
}
