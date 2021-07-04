#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll res = 2*n, lcm = 1;
        for (ll i = 2; i < 42; i++) {
            lcm = lcm * i / __gcd(lcm, i);
            res += floorl(1.0L * n / lcm);
            res %= MOD;
        }
        cout << res << '\n';
    }
    return 0;
}