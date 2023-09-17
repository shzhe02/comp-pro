#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define PB push_back
#define SQ(a) (a) * (a)

bool checkeq(vector<char> a, vector<char> b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

void tempswap(int pos, vector<char> target) {
  for (int c = 65; c < 91; ++c) {
    char tmp = char(c);
    if (tmp == target[max(pos - 1, 0)] || tmp == target[min(pos + 1, int(target.size()) - 1)] || tmp == target[pos]) {
      continue;
    } else {
      target[pos] = tmp;
      break;
    }
  }
}

void fix(vector<char> target, vector<char> ref) {
  for (int i = 0; i < ref.size(); ++i) {
    if (target[i] == ref[i]) { // Same character, no need to change;
      continue;
    } else if (i + 1 < ref.size() && target[i + 1] == ref[i] && ref[i + 1] == target[i]) { // Check for swap
      tempswap(i + 1, target);
    } else if (i - 1 >= 0 && target[i - 1] == ref[i] && ref[i - 1] == target[i]) { // Check for skipped swap
      tempswap(i, target);
    } else { // Free to change
      target[i] = ref[i];
      i++; // Skip the next one
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string a, b;
  cin >> a >> b;
  vector<char> av(a.begin(), a.end());
  vector<char> bv(b.begin(), b.end());
  vector<char> curr = av;

  for (auto i : curr) {
    cout << i;
  }
  cout << '\n';
  
  while (!checkeq(curr, bv)) {
    fix(curr, bv);
    for (auto i : curr) {
      cout << i;
    }
    cout << '\n';
  }
}
