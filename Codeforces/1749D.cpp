#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = 998244353;
constexpr ll INF = 1e12;

bool is_prime(ll n) {
    // this's enough, since the product of the following prime numbers is greater than 1e12
    set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    return primes.find(n) != primes.end();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> mini(n+1);
    mini[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (mini[i-1] == INF)
            mini[i] = INF;
        else if (is_prime(i))
            mini[i] = min(INF, mini[i-1]*i);
        else
            mini[i] = mini[i-1];
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (mini[i] == INF) break;
        ll temp_res = 1;
        for (int j = 1; j <= i; j++)
            temp_res = temp_res * ((m / mini[j]) % MOD) % MOD;
        res = (res + temp_res) % MOD;
    }
    m %= MOD;
    ll all = 0, pow_m = 1;
    for (int i = 1; i <= n; i++) {
        pow_m = pow_m * m % MOD;
        all = (all + pow_m) % MOD;
    }
    cout << (MOD + all - res) % MOD << '\n';
    return 0;
}