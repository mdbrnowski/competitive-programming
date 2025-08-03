#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll mod = 1e9 + 7;

ll binom(ll n, ll a) {
    vector<ll> inv(a + 1);
    inv[1] = 1;
    for (int i = 2; i <= a; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    ll res = 1;
    for (int i = 1; i <= a; i++)
        res = res * (n - i + 1) % mod * inv[i] % mod;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;

        ll n = ((a - 1) * k + 1) % mod;
        ll m = ((b - 1) * k % mod * binom(n, a) + 1) % mod;

        cout << n << ' ' << m << '\n';
    }
}
