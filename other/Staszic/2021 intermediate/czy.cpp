#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_P = 1e6+3;

void sieve(vector<int>& primes) {
    vector<bool> is_prime(MAX_P, true);
    for (int i = 2; i*i < MAX_P; i++)
        if (is_prime[i])
            for (int j = i*i; j < MAX_P; j += i)
                is_prime[j] = false;
    for (int i = 2; i < MAX_P; i++)
        if (is_prime[i]) primes.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> primes;
    sieve(primes);

    vector<int> factor(MAX_P, 0);
    for (auto p : primes)
        for (int i = 1; i * p < MAX_P; i++)
            factor[i * p] = p;

    while (t--) {
        int x;
        cin >> x;
        multiset<int> res;
        while (x > 1) {
            res.insert(factor[x]);
            x /= factor[x];
        }
        for (auto r : res) cout << r << ' ';
        cout << '\n';
    }
    return 0;
}