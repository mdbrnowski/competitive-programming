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

        vi even, odd;
        for (int i = 0; i < n; i += 2)
            even.push_back(a[i]);
        for (int i = 1; i < n; i += 2)
            odd.push_back(a[i]);

        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                res -= a[i];
            else
                res += a[i];
        }

        ll best_swap = (n - 1) / 2 * 2;  // best with swap of the same parity
        ll min_even = 1e12, max_odd = -1e12;
        for (auto& x : a) x *= 2;  // trick; swapping is 2 * |a - b|, "cost" only once
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                max_odd = max(max_odd, (ll)a[i]);
                best_swap = max(best_swap, a[i] - min_even);
            } else {
                min_even = min(min_even, (ll)a[i]);
                best_swap = max(best_swap, max_odd - a[i]);
            }
            min_even--, max_odd++;
        }

        cout << res + best_swap << '\n';
    }
}
