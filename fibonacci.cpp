#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1000000007;

pair<ll, ll> fib (ll n) {
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);
    ll c = (p.first * (2 * p.second - p.first)) % MOD;
    ll d = (p.first * p.first + p.second * p.second) % MOD;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << (fib(n).first + 1000000007) % MOD;
    return 0;
}
