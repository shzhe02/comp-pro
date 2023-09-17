#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > sum + 1) {
      break;
    }
    sum += arr[i];
  }
  cout << sum + 1;
}
