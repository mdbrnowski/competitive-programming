#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

void calc_primes(int n, vi& primes) {
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

bool factorize(int x, vi& primes, unordered_set<int>& s) {
    for (auto p : primes) {
        if (x % p == 0) {
            if (s.find(p) != s.end())
                return true;
            s.insert(p);
        }
        while (x % p == 0)
            x /= p;
    }
    if (x > 1) {
        if (s.find(x) != s.end())
            return true;
        s.insert(x);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vi primes;
    calc_primes(sqrt(1e9), primes);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a) cin >> x;
        unordered_set<int> s;
        bool ok = false;
        for (auto x : a) {
            if (factorize(x, primes, s)) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
