#include <iostream>
#include <ostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b > a) {
      int temp = a;
      a = b;
      b = temp;
    }
    if (a > (b << 1) || (2 * b - a) % 3) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}