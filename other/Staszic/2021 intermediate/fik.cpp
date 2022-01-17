#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};
    auto [p, r] = fib(n / 2);
    ll c = (p * (2 * r - p + MOD)) % MOD;
    ll d = (p * p + r * r) % MOD;
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    a++, b++;
    auto fib_a = fib(a-1), fib_b = fib(b);
    ll res = fib_b.first * fib_b.second % MOD - fib_a.first * fib_a.second % MOD;
    cout << (res + MOD) % MOD << '\n';
    return 0;
}