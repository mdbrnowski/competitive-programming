#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a)
            cin >> x;

        ll res = 0;
        for (int i = 0; i < n - 2; i += 2) {
            int r = max(0, a[i] + a[i + 2] - a[i + 1]);
            res += r;
            int r1 = min(a[i + 2], r);
            a[i + 2] -= r1;
            r -= r1;
            int r2 = min(a[i], r);
            a[i] -= r2;
            r -= r2;
        }
        if (n % 2 == 0) {
            int r = max(0, a[n - 2] - a[n - 1]);
            res += r;
            a[n - 2] -= r;
        }

        cout << res << '\n';
    }
}
