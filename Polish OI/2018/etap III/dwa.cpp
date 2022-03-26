#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ll> cll;

inline ld arg(cll z) {
    // function must be overridden because it returns
    // a long long by default, which makes no sense
    return atan2l(z.imag(), z.real());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n = n * 2;
    vector<cll> a(n);
    for (int i = 0; i < n; i += 2) {
        int x, y;
        cin >> x >> y;
        a[i] = cll{x, y};
        a[i + 1] = -a[i];
    }
    sort(a.begin(), a.end(), [](cll v, cll u) { return arg(v) < arg(u); });

    ll res = 0;
    int head = 1, tail = 0;  // range [tail, head)
    cll cur = a[0];
    while (tail < n) {
        while (head < n && arg(a[head]) < arg(a[tail]) + M_PI) {
            cur += a[head];
            head++;
        }
        res = max(res, norm(cur));
        cur -= a[tail];
        tail++;
    }

    cout << res << '\n';
    return 0;
}