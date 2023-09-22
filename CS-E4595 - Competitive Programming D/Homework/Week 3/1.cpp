#include <bits/stdc++.h>

using namespace std;

int parent(int node) {
  return (node - 1) >> 1;
}

int leftChild(int node) {
  return (node << 1) + 1;
}

int rightChild(int node) {
  return (node + 1) << 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int treeSize = 1;
  while (treeSize < n) {
    treeSize <<= 1;
  }
  treeSize = (treeSize << 1) - 1;
  // === build tree === 
  vector<int> tree(treeSize);
  for (int i = tree.size() >> 1; i < (tree.size() >> 1) + n; ++i) {
    cin >> tree[i];
  }
  for (int i = (tree.size() >> 1) + n; i < treeSize; ++i) {
    tree[i] = numeric_limits<int>::max();
  }
  for (int i = (tree.size() >> 1) - 1; i >= 0; --i) {
    tree[i] = min(tree[leftChild(i)], tree[rightChild(i)]);
  }
  // === build queries ===
  for (int i = 0; i < q; ++i) {
    int query, j, m;
    cin >> query >> j >> m;
    if (query == 1) {
      int offset = tree.size() >> 1;
      int k = j - 1 + offset;
      tree[k] = m;
      for (k = parent(k); k >= 0; k = parent(k)) {
        tree[k] = min(tree[leftChild(k)], tree[rightChild(k)]);
      }
    } else {
      int offset = tree.size() >> 1;
      int a = j - 1 + offset;
      int b = m - 1 + offset;
      int best = numeric_limits<int>::max();
      while (a <= b) {
        // ensuring a is always on left child and b is always on right child
        if (!(a % 2)) { // if left cursor is on right child, 
          best = min(best, tree[a++]);
        }
        if (b % 2) { // if right cursor is on left child
          best = min(best, tree[b--]);
        }
        // go to parents
        a = parent(a);
        b = parent(b);
      }
      cout << best << '\n';
    }
  }
}
