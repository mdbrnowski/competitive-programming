#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, s;
    cin >> n >> m >> s;
    vector<pair<ll, ll>> a(m);
    for (auto& x : a)
        cin >> x.first >> x.second;

    sort(a.begin(), a.end());

    auto cmp = [s](const ll x, const ll y) {
        if (abs(s - x) != abs(s - y))
            return abs(s - x) < abs(s - y);
        return x < y;
    };
    ll res = 1e18, p;
    for (int i = 0; i < m; i++) {
        p = a[i].first;
        if (p > 1 && (i == 0 || a[i - 1].second != p - 1)) {
            res = min(res, p - 1, cmp);
        }

        p = a[i].second;
        if (p < n && (i == m - 1 || a[i + 1].first != p + 1)) {
            res = min(res, p + 1, cmp);
        }
    }
    cout << res << '\n';
}
