#include <iostream>

using namespace std;

int main() {
  long n;
  cin >> n;
  long sum = (n * (n + 1)) / 2;
  for (int i = 0; i < (n - 1); ++i) {
    int k;
    cin >> k;
    sum -= k;
  }
  cout << sum;
}
