#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto& x : p) cin >> x;

        vector<vector<int>> part(n, vector<int>(n, 0));  // part[b][i] - number of pairs (b, d) : d is in [b+1, n)
        for (int b = 1; b < n; b++) {
            for (int d = b + 1; d < n; d++)
                if (p[b] > p[d])
                    part[b][d]++;
            partial_sum(part[b].begin(), part[b].end(), part[b].begin());
        }

        ll res = 0;
        for (int c = 2; c < n - 1; c++) {
            ll cur = 0;
            for (int a = c - 2; a >= 0; a--) {
                cur += part[a + 1][n - 1] - part[a + 1][c];
                if (p[a] < p[c])
                    res += cur;
            }
        }
        cout << res << '\n';
    }
    return 0;
}