#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

ll power(ll base, ll power) {
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
    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << power(a, b) << '\n';
    }
    return 0;
}