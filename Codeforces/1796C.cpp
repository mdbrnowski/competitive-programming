#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int k2 = 0, pow2 = 1;
        while (l * pow2 * 2 <= r)
            k2 += 1, pow2 *= 2;

        int res = r / pow2 - l + 1;

        if (pow2 > 1) {
            pow2 = pow2 / 2 * 3;
            res += max(0, (r / pow2 - l + 1)) * k2;
        }

        cout << k2 + 1 << ' ' << res << '\n';
    }
    return 0;
}
