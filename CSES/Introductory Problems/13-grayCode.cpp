#include <atomic>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int bits = 1;
  vector<int> out;
  out.push_back(0);
  out.push_back(1);
  while (--n) {
    // First, mirror contents.
    for (int i = out.size() - 1; i >= 0; i--) {
      out.push_back(out[i]);
    }
    // Next, add a most significant bit to the first half of the elements.
    int msb = 1 << bits;
    for (int i = 1 << bits; i < 1 << (bits + 1); i++) {
      out[i] = out[i] | msb;
    }
    bits++;
  }
  for (int j : out) {
    for (int i = bits - 1; i >= 0; i -= 1) {
      cout << ((j & 1 << i) ? 1 : 0);
    }
    cout << "\n";
  }
}
