#include <iostream>
#include <vector>

using namespace std;

long inner(vector<int> arr, int elem, long sum_a, long sum_total) {
  if (elem == 0) {
    return abs(sum_total - sum_a - sum_a);
  }

  return min(
    inner(arr, elem - 1, sum_a + arr[elem], sum_total),
    inner(arr, elem - 1, sum_a, sum_total)
  );
}

int main() {
  int n;
  cin >> n;
  long sum_total = 0;
  vector<int> apples;
  while (n--) {
    int p;
    cin >> p;
    sum_total += p;
    apples.push_back(p);
  }
  cout << inner(apples, apples.size() - 1, 0, sum_total);
}
