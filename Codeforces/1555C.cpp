#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> a(m), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        int sum_a = accumulate(a.begin(), a.end(), 0), sum_b = 0;
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            sum_a -= a[i];
            res = min(res, max(sum_a, sum_b));
            sum_b += b[i];
        }
        cout << res << '\n';
    }
    return 0;
}