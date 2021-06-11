#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        long long res = 0;
        for (auto x : a) {
            int begin = lower_bound(a.begin(), a.end(), l - x) - a.begin();
            int end = upper_bound(a.begin(), a.end(), r - x) - a.begin();
            res += end - begin;
            if (l <= 2 * x && 2 * x <= r) res--;
        }
        cout << res / 2 << '\n';
    }
    return 0;
}