#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string text;
  getline(cin, text);
  string nT;
  getline(cin, nT);
  int n = nT[0] - '0';
  unsigned long long a = 911382323;
  unsigned long long b = 972663749;
  vector<pair<unsigned long long, int>> buzzwords(n); // hash, size
  for (auto &word : buzzwords) {
    string thing;
    getline(cin, thing);
    unsigned long long prev = thing[0];
    for (int i = 1; i < thing.size(); ++i) {
      prev = (prev * a + thing[i]) % b;
    }
    word = {prev, thing.size()};
  };
  unsigned long long count = 0;
  for (auto hash : buzzwords) {
    if (hash.second > text.size()) continue;
    // first, calculate initial hash
    unsigned long long currHash = 0;
    unsigned long long factor = 1;
    for (int i = 0; i < hash.second; ++i) {
      currHash = (currHash * a + text[i]) % b;
      if (i < hash.second - 1) {
        factor = (factor * a) % b;
      }
    }
    if (currHash == hash.first) count++;
    for (int i = 1; i <= text.size() - hash.second; ++i) {
      // remove last character in window
      currHash = (currHash - text[i - 1] * factor % b + b) % b;
      // add new character to window
      currHash = ((currHash * a) % b + text[i + hash.second - 1]) % b;
      if (currHash == hash.first) count++;
    }
  }
  cout << count;
}
