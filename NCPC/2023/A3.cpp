#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (n < pow(k, k)) {
        while (n > k) {
            int curr = k;
            while (curr * (curr + 1) <= n) {
                curr = curr * (curr + 1);
            }
            ans += curr / k;
            if (curr % k > 0)
                ans++;

            cout << "curr " << curr << endl;
            n -= (curr + 1);
        }
    } else {
        ans = n - pow(k, k);
    }
    
    cout << ans << endl;
    return 0;
}
