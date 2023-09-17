#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  n--;
  int out = 2;
  while (n--) {
    out <<= 1;
    out %= 1000000007;
  }
  cout << out;
}
