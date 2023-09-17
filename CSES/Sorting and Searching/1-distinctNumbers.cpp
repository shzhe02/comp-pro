#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> nums;
  int n;
  cin >> n;
  while (n--) {
    int p;
    cin >> p;
    nums.insert(p);
  }
  cout << nums.size();
}
