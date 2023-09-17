#include <iostream>

using namespace std;

int main() {
  int n, last;
  long moves = 0;
  cin >> n >> last;
  for (int k = 0; k < n - 1; ++k) {
    int curr;
    cin >> curr;
    if (curr < last) {
      moves += last - curr;
    } else {
      last = curr;
    }
  }
  cout << moves;
}
