#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);
        for (auto& x : q) cin >> x;
        vector<int> p(n, -1);
        p[0] = q[0];
        for (int i = 1; i < n; i++)
            if (q[i] != q[i-1]) p[i] = q[i];

        set<int> used(p.begin(), p.end());
        int x = 1;
        for (int i = 0; i < n; i++) {
            if (p[i] > 0) cout << p[i] << ' ';
            else {
                while (used.count(x)) x++;
                cout << x << ' ';
                x++;
            }
        }
        cout << '\n';

        set<int> unused;
        for (int i = 1; i <= n; i++)
            if (!used.count(i)) unused.insert(i);
        for (int i = 0; i < n; i++) {
            if (p[i] > 0) cout << p[i] << ' ';
            else {
                auto x = prev(unused.upper_bound(q[i]));
                cout << *x << ' ';
                unused.erase(x);
            }
        }
        cout << '\n';
    }
    return 0;
}