#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ld>> a(n, vector<ld>(n));
    for (auto& row : a)
        for (auto& x : row)
            cin >> x;

    int m = (1 << n) - 1;
    vector<vector<ld>> p(m + 1, vector<ld>(n));

    for (int mask = 1; mask <= m; mask++) {
        for (int i = 0; i < n; ++i)
            p[mask][i] = (mask == (1 << i));

        int c = __builtin_popcount(mask);
        if (c <= 1)
            continue;
        int meetings = c * (c - 1) / 2;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0)
                continue;
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) == 0)
                    continue;
                for (int k = 0; k < n; k++) {
                    p[mask][k] += a[i][j] * p[mask ^ (1 << j)][k] / meetings;
                    p[mask][k] += a[j][i] * p[mask ^ (1 << i)][k] / meetings;
                }
            }
        }
    }

    cout << setprecision(6) << fixed;
    for (ld x : p[m])
        cout << x << ' ';
    cout << '\n';
    return 0;
}
