#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9 + 7;

ll fast_power(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power & 1)
            res = res * base % MOD;
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
        int l, r, k;
        cin >> l >> r >> k;
        int m = (10 + k - 1) / k;  // ceil(10 / k)
        cout << fast_power(m, l) * (fast_power(m, r - l) - 1) % MOD << '\n';
    }
    return 0;
}
