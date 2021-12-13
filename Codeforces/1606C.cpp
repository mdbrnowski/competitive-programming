#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            x = pow(10, x);
        }
        k++;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = k;
            if (i+1 < n) cnt = min(cnt, a[i+1] / a[i] - 1);
            res += (ll) a[i] * cnt;
            k -= cnt;
        }
        cout << res << '\n';
    }
    return 0;
}