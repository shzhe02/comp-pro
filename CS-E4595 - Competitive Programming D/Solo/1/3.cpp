#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define PB push_back
#define SQ(a) (a) * (a)


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int max = 0;
  int curr = 0;
  priority_queue<int, vector<int>, greater<int>> enter;
  priority_queue<int, vector<int>, greater<int>> leave;
  while (n--) {
    int l, r;
    cin >> l >> r;
    enter.push(l);
    leave.push(r);
  }
  while (!enter.empty()) {
    int now = enter.top();
    curr++;
    enter.pop();
    if (now > leave.top()) {
      leave.pop();
      curr--;
    }
    max = std::max(curr, max);
  }
  cout << max;
}
