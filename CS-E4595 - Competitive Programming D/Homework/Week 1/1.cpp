#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
  int n, m;
  unordered_map<int, unordered_set<int>> roads; // from => [to...]
  unordered_set<int> newRoads; 
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    roads[a].insert(b);
    roads[b].insert(a);
  }
  // Using BFS
  unordered_set<int> visited;
  queue<int> toVisit;
  toVisit.push(1);
  while (true) {
    while(!toVisit.empty()) {
      int cursor = toVisit.front();
      visited.insert(cursor);
      unordered_set<int> nexts = roads[cursor];
      for (int next : nexts) {
        if (!visited.count(next)) {
          toVisit.push(next);
        }
      }
      toVisit.pop();
    } // BFS done
    if (int(visited.size()) == n) { // If we have visited every city, we are done.
      break;
    }
    // If we haven't, find an unvisited city and connect it to city 1.
    int unvisited = 1;
    while (visited.count(unvisited)) {
      unvisited++;
    }
    // Connect to 1 and add new road
    roads[1].insert(unvisited);
    roads[unvisited].insert(1);
    newRoads.insert(unvisited);
    // Restart BFS
    toVisit.push(unvisited);
  }
  cout << newRoads.size() << '\n';
  for (int dest : newRoads) {
    cout << "1 " << dest << '\n';
  }
}
