
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_map<char, int> convert = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  while (n--) {
    string roman;
    cin >> roman;
    vector<int> nums(roman.size());
    for (int i = 0; i < roman.size(); ++i) {
      nums[i] = convert[roman[i]];
    }
    int total = 0;
    for (int i = 0; i < roman.size(); ++i) {
      total += nums[i];
    }
    vector<bool> checked(roman.size());
    for (int i = 1; i < roman.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        int k = 1;
        while (i - k >= 0 && nums[i] > nums[i - k] && nums[i - k] <= nums[i - k + 1]) {
          if (!checked[i - k]) {
            total -= nums[i - k] * 2;
            checked[i - k] = true;
          }
          k++;
        }
      }
    }
    cout << total << '\n';
  }
}

