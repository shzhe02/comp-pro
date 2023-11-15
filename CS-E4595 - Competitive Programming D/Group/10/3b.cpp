#include <bits/stdc++.h>
using namespace std;

#define int long long

// To find the closest pair of points
long closestPair(vector<pair<int, int> > coordinates, int n)
{
    int i;
    // Vector pair to store points on plane
    vector<pair<int, int> > v;
    for (i = 0; i < n; i++)
        v.push_back({ coordinates[i].first,
                      coordinates[i].second });
 
    // Sort them according to their
    // x-coordinates
    sort(v.begin(), v.end());
 
    // Minimum distance b/w points
    // seen so far
    unsigned long long d = numeric_limits<unsigned long long>::max();
 
    // Keeping the points in
    // increasing order
    set<pair<int, int> > st;
    st.insert({ v[0].first, v[0].second });
 
    for (i = 1; i < n; i++) {
        auto l = st.lower_bound(
            { v[i].first - d, v[i].second - d });
        auto r = st.upper_bound(
            { v[i].first, v[i].second + d });
        if (l == st.end())
            continue;
 
        for (auto p = l; p != r; p++) {
            pair<int, int> val = *p;
            unsigned long long dis = (v[i].first - val.first)
                           * (v[i].first - val.first)
                       + (v[i].second - val.second)
                             * (v[i].second - val.second);
 
            // Updating the minimum
            // distance dis
            if (d > dis)
                d = dis;
        }
        st.insert({ v[i].first, v[i].second });
    }
 
    return d;
}
 
// Driver code
signed main()
{
 
    // Points on a plane P[i] = {x, y}
    vector<pair<int, int>> P;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
     int a, b;
    cin >> a >> b;
    P.push_back({a, b});
  }
    // Function call
    cout << closestPair(P, n);
    return 0;
}
