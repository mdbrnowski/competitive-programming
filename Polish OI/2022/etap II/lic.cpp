#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieve(ll n, vector<ll>& primes) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

void get_prime_factors(ll n, vector<ll>& primes, vector<ll>& pf) {
    for (auto p : primes) {
        if (n % p == 0)
            pf.push_back(p);
        while (n % p == 0)
            n /= p;
    }
    if (n != 1)
        pf.push_back(n);
}

ll count(ll m, vector<ll>& pf) {  // relatively prime numbers <= m with primes from pf
    vector<ll> parity(2, 0);
    ll i = (1LL << pf.size());
    while (--i) {
        ll mult = 1;
        for (int j = 0; j < (int) pf.size(); j++)
            if (i & (1 << j))
                mult *= pf[j];

        parity[__builtin_popcountll(i) & 1] += m / mult;
    }
    return m - (parity[1] - parity[0]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; int c;
    cin >> n >> k >> c;
    k--;

    vector<ll> primes;  // primes <= sqrt(n)
    sieve(sqrt(n), primes);
    vector<ll> pf;  // unique prime factors of n
    get_prime_factors(n, primes, pf);

    ll a = 0, b = 1e18;
    while (a <= b) {
        ll mid = (a + b) / 2;
        ll r = count(mid, pf);
        if (r == k) {a = mid; break;}
        else if (r < k) a = mid + 1;
        else b = mid - 1;
    }

    for (ll i = a + 1; c > 0; i++)
        if (gcd(i, n) == 1) {
            cout << i << ' ';
            c--;
        }
    cout << '\n';
    return 0;
}