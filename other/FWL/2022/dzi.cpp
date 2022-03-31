#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sieve(int n, vector<int>& primes) {
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < n; j += i)
            is_prime[j] = false;
    }
    for (int i = 0; i < n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

void factorize(ll x, vector<int>& primes, map<ll,int>& factors) {
    for (auto p : primes) {
        while (x % p == 0) {
            x /= p;
            factors[p]++;
        }
    }
    if (x > 1) {
        ll sqx = sqrt(x);
        if (sqx * sqx == x)
            factors[sqx] += 2;
        else
            factors[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Z;
    cin >> Z;
    vector<int> primes;
    sieve(1e7, primes);
    while (Z--) {
        ll n;
        cin >> n;
        map<ll,int> factors;
        factorize(n, primes, factors);
        int m = 1;
        for (auto [p, a] : factors)
            m = max(m, a);
        vector<ll> res(m, 1);
        for (auto [p, a] : factors)
            for (int i = 0; i < a; i++)
                res[i] *= p;
        reverse(res.begin(), res.end());

        cout << res.size() << '\n';
        for (auto r : res)
            cout << r << ' ';
        cout << '\n';
    }
    return 0;
}