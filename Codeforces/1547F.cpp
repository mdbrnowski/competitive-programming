#include <bits/stdc++.h>
using namespace std;

struct sparse_table {
    int n;
    vector<vector<int>> spt;
    sparse_table(vector<int> a) : n(a.size()), spt(n*2) {
        for (int i = 0; i < n; i++)
            spt[i].push_back(a[i]);
        for (int i = 0; i < n; i++)
            spt[i+n].push_back(a[i]);
        n *= 2;                       // make it cyclic
        for (int j = 1; (1<<j) <= n; j++)
            for (int i = 0; i + (1<<j) <= n; i++)
                spt[i].push_back(__gcd(spt[i][j-1], spt[i + (1<<j-1)][j-1]));
    }
    int gcd(int L, int R) {
        int j = __lg(R - L + 1);
        return __gcd(spt[L][j], spt[R - (1<<j) + 1][j]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int gcd = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            gcd = __gcd(gcd, a[i]);
        }
        for (auto& x : a) x /= gcd;
        auto spt = sparse_table(a);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = 2*n-1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (spt.gcd(i, m) == 1) r = m - 1;
                else l = m + 1;
            }
            res = max(res, l - i);
        }
        cout << res << '\n';
    }
    return 0;
}