#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a == b) {
            cout << min(x, y) / a << '\n';
            continue;
        } else if (a < b) swap(a, b);
        int l = 0, r = 1e9+7;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll right = floorl((x - m * b) * 1.0L / (a - b));
            ll left = ceill((y - m * a) * 1.0L / (b - a));
            if (max(left, 0LL) <= min(right, m)) l = m;
            else r = m;
        }
        cout << l << '\n';
    }
    return 0;
}