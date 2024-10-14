#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MAX_N = 1e18;

bool is_square(ll n) {
    ll x = sqrtl(n);
    return x * x == n;
}

__int128_t fast_pow(__int128_t a, int b) {
    __int128_t res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<ll> s;
    for (int p = 3; p < 60; p += 2) {
        for (ll i = 2; fast_pow(i, p) <= MAX_N; i++)
            s.insert(fast_pow(i, p));
    }
    for (auto it = s.begin(); it != s.end();) {
        if (is_square(*it))
            it = s.erase(it);
        else
            ++it;
    }
    vector<ll> v(s.begin(), s.end());

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll res = n - 1;
        res -= (ll)sqrtl(n) - 1;  // even gcd
        res -= upper_bound(v.begin(), v.end(), n) - v.begin();  // any other
        cout << res << '\n';
    }
    return 0;
}
