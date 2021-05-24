#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        int res = 1, min_diff = INT_MAX;
        for (int i = 1; i < n; i++) {
            min_diff = min(min_diff, a[i] - a[i-1]);
            if (a[i] > min_diff) break;
            res++;
        }
        cout << res << '\n';
    }
    return 0;
}