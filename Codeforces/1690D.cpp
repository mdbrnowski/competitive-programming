#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = (c == 'B');
        }
        int res = k, s = 0;
        for (int i = 0; i < k; i++)
            s += a[i];
        for (int i = 0; i <= n - k; i++) {
            res = min(res, k - s);
            s -= a[i];
            if (i < n - k)
                s += a[i + k];
        }
        cout << res << '\n';
    }
    return 0;
}