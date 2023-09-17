#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  for (int j = 2; j <= n; j += 2) { cout << j << " "; }
  for (int k = 1; k <= n; k += 2) { cout << k << " "; }
}