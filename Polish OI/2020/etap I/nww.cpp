#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<ll,pair<int,int>> res;
    for (ll a = 1; a < 2 * 1e6; a++) {
        ll lcm = a * (a+1) / __gcd(a, a+1);
        for (int k = 3; k < 53; k++) {
            ll gcd = __gcd(lcm, a+k-1);
            if (lcm / gcd > 1e18 / (a+k-1)) break;
            lcm = lcm / gcd * (a+k-1);
            if (!res.count(lcm)) res[lcm] = {a, a+k-1};
        }
    }
    int z;
    cin >> z;
    while (z--) {
        ll m;
        cin >> m;
        if (res.count(m)) cout << res[m].first << ' ' << res[m].second << '\n';
        else {
            ll a = sqrt(m);
            if (a * a >= m) a--;
            if (a * (a+1) == m) cout << a << ' ' << a+1 << '\n';
            else cout << "NIE\n";
        }
    }
    return 0;
}