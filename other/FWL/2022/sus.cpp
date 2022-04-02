#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void divisors_add(int x, vector<ll>& res, int r) {
    for (int i = 1; i * i < x; i++)
        if (x % i == 0)
            res[i] += r,
            res[x/i] += r;
    ll sqx = sqrt(x);
    if (sqx * sqx == x)
        res[sqx] += r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Z;
    cin >> Z;
    while (Z--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        vector<int> b(a);
        sort(b.begin(), b.end());
        vector<ll> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            auto prev = b.begin();
            for (int j = i; j <= n + i; j += i) {
                auto it = upper_bound(b.begin(), b.end(), j);
                res[i] += (it - prev) * (ll) j / i;
                prev = it;
            }
        }

        while (q--) {
            int c, k;
            cin >> c >> k;
            if (c == 1) {
                k--;
                divisors_add(a[k], res, 1);
                a[k]++;
            }
            else if (c == 2) {
                k--;
                a[k]--;
                divisors_add(a[k], res, -1);
            }
            else
                cout << res[k] << '\n';
        }
    }
    return 0;
}