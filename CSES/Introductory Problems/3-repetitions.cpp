#include <cstddef>
#include <iostream>

using namespace std;

int main() {
  string dna;
  cin >> dna;
  int currLen = 1;
  int longest = 0;
  char last = '\0';
  for (char& c : dna) {
    if (c == last) {
      currLen++;
    } else {
      longest = max(longest, currLen);
      currLen = 1;
    }
    last = c;
  }
  cout << max(currLen, longest);
}
