#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  vector<int> newRoads; 
  cin >> n >> m;
  vector<vector<int>> roads(n + 1); // from => [to...]
  while (m--) {
    int a, b;
    cin >> a >> b;
    roads[a].push_back(b);
    roads[b].push_back(a);
  }
  // Using BFS
  vector<bool> visited(n + 1, false);
  visited[0] = true;
  queue<int> toVisit;
  toVisit.push(1);
  int unvisited = 2;
  // Quickly deal with all orphan cities
  for (int i = 2; i <= n; ++i) {
    if (roads[i].empty()) {
      visited[i] = true;
      newRoads.push_back(i);
    }
  }
  // Actual algorithm
  while (true) {
    while(!toVisit.empty()) {
      int cursor = toVisit.front();
      toVisit.pop();
      visited[cursor] = true;
      for (int next : roads[cursor]) {
        if (!visited[next]) {
          toVisit.push(next);
        }
      }
    } // BFS done
    auto target = find(visited.begin(), visited.end(), false);
    if (target == visited.end()) {
      break;
    } else {
      unvisited = target - visited.begin();
    }
    // Connect to 1 and add new road
    roads[1].push_back(unvisited);
    roads[unvisited].push_back(1);
    newRoads.push_back(unvisited);
    // Restart BFS
    toVisit.push(unvisited);
  }
  cout << newRoads.size() << '\n';
  for (int dest : newRoads) {
    cout << "1 " << dest << '\n';
  }
}
