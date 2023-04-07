#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void insert_if_min(unordered_map<int,int>& m, int key, int val) {
    auto it = m.find(key);
    if (it == m.end())
        m[key] = val;
    else
        it->second = min(it->second, val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<vi> a(l + r, vi(n));
    for (int i = 0; i < l; i++)
        for (auto& x : a[i])
            cin >> x;
    for (int i = l; i < l + r; i++)
        for (auto& x : a[i])
            cin >> x;
    int sumL = 0, sumR = 0;
    for (int i = 0; i < l + r; i++) {
        reverse(a[i].begin(), a[i].end());
        partial_sum(a[i].begin(), a[i].end(), a[i].begin());
        if (i < l) sumL += a[i][n-1];
        else sumR += a[i][n-1];
    }
    unordered_map<int,int> dpL, dpR, new_dpL, new_dpR;
    dpL[sumL] = dpR[sumR] = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++)
            for (auto [x, val] : dpL)
                insert_if_min(new_dpL, x - a[i][j], val + 1 + j);
        for (auto [x, val] : new_dpL)
            insert_if_min(dpL, x, val);
        new_dpL.clear();
    }
    for (int i = l; i < l + r; i++) {
        for (int j = 0; j < n; j++)
            for (auto [x, val] : dpR)
                insert_if_min(new_dpR, x - a[i][j], val + 1 + j);
        for (auto [x, val] : new_dpR)
            insert_if_min(dpR, x, val);
        new_dpR.clear();
    }
    int res = 1e9;
    for (auto [x, val] : dpL) {
        auto it = dpR.find(x);
        if (it != dpR.end())
            res = min(res, val + it->second);
    }
    cout << res << '\n';
    return 0;
}