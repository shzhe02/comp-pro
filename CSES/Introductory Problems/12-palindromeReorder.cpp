#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string in;
  cin >> in;
  string half = "";
  vector<int> chars(26);
  for (auto ch : in) chars[ch - 'A']++;
  bool odd = false;
  int pos = -1;
  for (int i = 0; i < 26; ++i) {
    if (chars[i] % 2) {
      if (odd == false) {
        odd = true;
        pos = i;
      } else {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
    } else {
      half += string(chars[i] / 2, 'A' + i);
    }
  }
  cout << half;
  if (odd) {
    cout << string(chars[pos], 'A' + pos);
  }
  reverse(half.begin(), half.end());
  cout << half;
  return 0;
}
