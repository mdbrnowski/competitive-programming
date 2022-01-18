#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 123456789;

pair<ll,ll> fib(int n) {
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
    int n;
    cin >> n;
    cout << fib(n).first << '\n';
    return 0;
}