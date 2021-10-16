#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        set<int> bins;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '1') bins.insert(i);
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int closest = INT_MAX;
            auto lb = bins.lower_bound(i);
            if (lb != bins.end()) closest = min(closest, *lb - i);
            if (lb != bins.begin()) closest = min(closest, i - *(--lb));
            res += closest;
        }
        cout << "Case #" << tc << ": " << res << '\n';
    }
    return 0;
}