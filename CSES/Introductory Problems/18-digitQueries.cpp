#include <iostream>
#include <string>
#include <utility>

using namespace std;

void digitQuery(long query) {
  long remaining = query;
  int digitSection = 1;
  long power = 1;
  while (remaining > 9 * power * digitSection) {
    remaining -= 9 * power * digitSection;
    power *= 10;
    digitSection++;
  }
  remaining--;
  int digit = remaining % digitSection;
  long targetNum = power + remaining / digitSection;
  cout << to_string(targetNum)[digit] << '\n';
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    long query;
    cin >> query;
    digitQuery(query);
  }
}
