#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<vector<int>> memo;
constexpr int MEMO_K = 50;
constexpr int MEMO_N = 100000;

void sieve(int B) {
    vector<bool> is_prime(B + 1, true);
    for (int i = 2; i * i <= B; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= B; j += i)
            is_prime[j] = false;
    }
    for (int i = 2; i <= B; i++)
        if (is_prime[i])
            primes.push_back(i);
}

int g(int n, int k) {
    if (k < 0) return (n > 1);
    if (primes[k] == 2) return __lg(n) + 1;
    if (primes[k] >= n) return n;
    if (n < MEMO_N && k < MEMO_K && memo[n][k] >= 0)
        return memo[n][k];
    int res = g(n, k - 1) + g(n / primes[k], k);
    if (n < MEMO_N && k < MEMO_K)
        memo[n][k] = res;
    return res;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, B;
    cin >> n >> m >> B;
    sieve(B);

    if (n / 800 > m) {
        // sieve-like solution
        vector<int> v(m+1);
        iota(v.begin(), v.end(), n);
        for (auto p : primes) {
            int i = p - n % p;
            if (i == p) i = 0;
            for (; i <= m; i += p)
                while (v[i] % p == 0)
                    v[i] /= p;
        }
        int res = 0;
        for (auto x : v)
            if (x == 1) res++;
        cout << res << '\n';
    }
    else {
        // recursive solution
        memo.resize(MEMO_N, vector<int>(MEMO_K, -1));
        int k = primes.size() - 1;
        cout << g(n + m, k) - g(n - 1, k) << '\n';
    }
    return 0;
}