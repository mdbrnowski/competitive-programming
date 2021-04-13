#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int k = r - l + 1;
        set<int> in_range;
        for (int x = n; x >= 1; x--) {
            if (!k) break;
            if (s <= k*(2*x+1-k)/2 && (s-x) >= k*(k-1)/2) {
                s -= x;
                k--;
                in_range.insert(x);
            }
        }
        if (s > 0) {
            cout << -1 << '\n';
            continue;
        }
        int i = 0, x = 1;
        while (i < n) {
            if (i == l - 1) {
                for (auto y : in_range) cout << y << ' ';
                i += r - l + 1;
                continue;
            } else i++;
            while (count(in_range.begin(), in_range.end(), x)) x++;
            cout << x << ' ';
            x++;
        }
        cout << '\n';
    }
    return 0;
}