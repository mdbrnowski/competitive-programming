#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll res = 1;
    int m = n / 6;
    vector<ll> inv(m+1, 1);
    for (int i = 2; i <= m; i++)
        inv[i] = MOD - (ll) (MOD / i) * inv[MOD % i] % MOD;
    for (int i = 1; i <= m; i++)
        res = res * (i + m) % MOD,
        res = res * inv[i] % MOD;
    // res = \binom{2m}{m}

    for (int i = 0; i < n; i += 3) {
        array<int,3> a;
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if (a[0] == a[1] && a[1] != a[2])
            res = res * 2 % MOD;
        if (a[0] == a[1] && a[1] == a[2])
            res = res * 3 % MOD;
    }
    cout << res << '\n';
    return 0;
}
