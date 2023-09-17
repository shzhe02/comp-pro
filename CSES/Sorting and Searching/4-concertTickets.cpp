#include <iostream>
#include <set>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  multiset<int> tickets;
  cin >> n >> m;
  while (n--) {
    int ticket;
    cin >> ticket;
    tickets.insert(ticket);
  }
  while (m--) {
    int customer;
    cin >> customer;
    auto found = tickets.upper_bound(customer);
    if (found != tickets.begin()) {
      cout << *(--found) << '\n';
      tickets.erase(found);
    } else {
      cout << -1 << '\n';
    }
  }
}
