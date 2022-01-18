#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int inverse(ll x, int mod) {
    int power = mod - 2;
    ll res = 1;
    while (power) {
        if (power & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        power >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    ll a = 1, b = 1;
    for (int i = n + 1; i <= n + m; i++)
        a = a * i % p;
    for (int i = 1; i <= m; i++)
        b = b * i % p;
    cout << a * inverse(b, p) % p << '\n';
    return 0;
}