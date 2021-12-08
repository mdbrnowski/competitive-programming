#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;
#define bad {cout << 0 << '\n'; return 0;}
#define set_hat(i, x) {if (v[i] && v[i] != x) bad; v[i] = x;}
#define multiply_and_reset {if (s > 0) res = res * s % MOD; s = 0;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n), v(n, 0);
    for (auto& x : h) cin >> x;

    vector<int> used(n+1, 0);
    for (int i = 0; i < n; i++) {
        used[h[i]]++;
        if (used[h[i]] > 2) bad;
        if (used[h[i]] == 2 && (i <= 1 || h[i] != h[i-2])) bad;
    }

    v[1] = h[0];
    set_hat(n-2, h[n-1]);

    for (int i = 0; i < n-2; i++)
        if (h[i] == h[i+2]) v[i+1] = h[i];

    for (int i = 1; i < n-1; i++) {
        if (v[i-1] && v[i-1] != h[i])
            set_hat(i+1, h[i]);
        if (v[i+1] && v[i+1] != h[i])
            set_hat(i-1, h[i]);
    }
    for (int i = n-2; i > 0; i--) {
        if (v[i+1] && v[i+1] != h[i])
            set_hat(i-1, h[i]);
        if (v[i-1] && v[i-1] != h[i])
            set_hat(i+1, h[i]);
    }

    int free_hats = 0;
    for (int i = 1; i <= n; i++)
        free_hats += (used[i] == 0);

    ll res = 1;
    for (int i = 2; i <= free_hats; i++)
        res = res * i % MOD;

    int s = 0;
    for (int i = 0; i < n; i += 2) {
        if (v[i] == 0) s++;
        else multiply_and_reset;
    }
    multiply_and_reset;
    for (int i = 1; i < n; i += 2) {
        if (v[i] == 0) s++;
        else multiply_and_reset;
    }
    multiply_and_reset;

    cout << res << '\n';
    return 0;
}