#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c;
vector<int> a, b;

int ok(ll x) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        // sum += 1 + (a * x) / b
        if (a[i] > 0 && x / b[i] > 1e9) return 2;
        ll k1 = a[i] / b[i], r1 = a[i] % b[i], k2 = x / b[i], r2 = x % b[i];
        sum += 1 + k1*k2*b[i] + k2*r1 + k1*r2 + r1*r2/b[i];
        if (sum > c) return 2;
    }
    if (sum < c) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll first = 1, last = 1e18;
    while (first <= last) {
        ll m = (first + last) / 2;
        if (ok(m) < 1) first = m + 1;
        else last = m - 1;
    }
    ll first_res = first;

    first = 1, last = 1e18;
    while (first <= last) {
        ll m = (first + last) / 2;
        if (ok(m) <= 1) first = m + 1;
        else last = m - 1;
    }
    ll last_res = first - 1;

    ll res = last_res - first_res + 1;
    if (last_res - first_res + 1 >= 1e18) res = -1;
    if (last_res < first_res) res = 0;
    cout << res << '\n';
    return 0;
}