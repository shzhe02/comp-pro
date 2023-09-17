#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string in;
  cin >> in;
  sort(in.begin(), in.end());
  vector<string> perms;
  do {
    perms.push_back(in);
  } while (next_permutation(in.begin(), in.end()));
  cout << perms.size() << "\n";
  for (string i : perms) {
    cout << i << "\n";
  }
}
