#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  while(n--) {
    cin >> arr[n];
  }
  sort(arr.begin(), arr.end());
  int mid = arr[arr.size() / 2];
  long cost = 0;
  for (int stick : arr) {
    cost += abs(stick - mid);
  }
  cout << cost;
}
