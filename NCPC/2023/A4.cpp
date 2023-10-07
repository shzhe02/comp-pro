#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> acc = {1};
    vector<bool> size = {k + 1};
    int top = 0;
    while (size[0] < n) {
        acc.push_back(acc[top] * k + 1);
        size.push_back(size[top] * k + 1);
        top++;
    }
    for ()
    return 0;
}
