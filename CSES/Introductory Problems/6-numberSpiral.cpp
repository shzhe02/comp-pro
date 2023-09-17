#include <iostream>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    long row, col;
    cin >> row >> col;
    if (row >= col) { // Bottom-left triangle
      long start = (row % 2) ? (row - 1) * (row - 1) + 1 : row * row;
      cout << ((row % 2) ? start + col - 1: start - col + 1) << endl;
    } else { // Top-right triangle
      long start = (col % 2) ? col * col : (col - 1) * (col - 1) + 1;
      cout << ((col % 2) ? start - row + 1 : start + row - 1) << endl;
    }
  }
}