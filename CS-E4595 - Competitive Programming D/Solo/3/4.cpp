#include <bits/stdc++.h>
#include <limits>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> particles(n);
  for (auto &a : particles) {
    cin >> a;
  }
  int cost = 0;
  while (n > 1) {
    int bestLeft = 0;
    int smallestDiff = numeric_limits<int>::max();
    for (int i = 0; i < n - 1; ++i) {
      if (abs(particles[i] - particles[i + 1]) < smallestDiff) {
        bestLeft = i;
        smallestDiff = abs(particles[i] - particles[i + 1]);
      }
    }
    cout << '\n';
    int a = particles[bestLeft];
    int b = particles[bestLeft + 1];
    cost += a * b - min(a, b) * min(a, b);
    particles[bestLeft] = a + b;
    particles.erase(particles.begin() + bestLeft + 1);
    n--;
    for (auto a : particles) {
      cout << a << ' ';
    }
    cout << '\n';
  }
  cout << cost;
}
