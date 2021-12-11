#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int fast_power(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % MOD;
        base = base * base % MOD;
        power >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll res = fast_power(2, n-1);
        int or_all = 0;
        for (int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            or_all |= x;
        }
        cout << res * or_all % MOD << '\n';
    }
    return 0;
}