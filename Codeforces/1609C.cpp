#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> is_prime(1e6+1, true);

void precalc_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 1e6+1; i++)
        if (is_prime[i] && (ll) i * i <= 1e6+1)
            for (int j = i * i; j <= 1e6+1; j += i)
                is_prime[j] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc_primes();
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (!is_prime[a[i]]) continue;
            int ones_r = 0, ones_l = 0;
            int j = i + e;
            while (j < n && a[j] == 1)
                j += e, ones_r++;
            j = i - e;
            while (j >= 0 && a[j] == 1)
                j -= e, ones_l++;
            res += (ll) (ones_r + 1) * (ones_l + 1) - 1;
        }
        cout << res << '\n';
    }
    return 0;
}