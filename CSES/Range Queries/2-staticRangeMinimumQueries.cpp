// #include <bits/stdc++.h>
// #include <cmath>
// #include <limits>

// using namespace std;

// int main() {
//   int n, q;
//   cin >> n >> q;
//   int m = floor(log2(n)) + 1;
//   int p = 1;
//   while (p < n) {
//     p <<= 1;
//   }
//   cout << m;
//   vector<vector<int>> table(m, vector<int>(p, numeric_limits<int>::max()));
//   for (int &a : table[0]) {
//     cin >> a;
//   }
//   // == sparse table ==
//   for (int i = 1; i < m; ++i) {
//     int cutoff = (1 << i) - 1;
//     for (int j = 0; j < m - cutoff; ++j) {
      
//     }
//   }
//   // == querying ==
//   while (q--) {
//     int a, b;
//     cin >> a >> b;
//   }
// }