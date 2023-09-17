#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (long k = 1; k <= n; ++k) {
    long combinations = k * k * (k * k - 1) / 2;
    if (k < 3) { cout << combinations << endl; }
    else {
      cout << combinations - 4 * (k - 1) * (k - 2) << endl;
    }
  }
}
