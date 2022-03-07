#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

vector<int> p;
vector<ll> f, g;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int _n) : n(1 << (__lg(_n) + 1)), tree(2 * n, 0) {
        for (int i = n; i < n + _n; i++)
            tree[i] = 1;
        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void erase(int i) {
        i = i - 1 + n;
        tree[i] = 0;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    int count_smaller(int i) {
        int res = 0;
        int a = n, b = i - 2 + n;
        while (a <= b) {
            if ((a & 1) == 1) res += tree[a++];
            if ((b & 1) == 0) res += tree[b--];
            a /= 2, b /= 2;
        }
        return res;
    }
};

int ans(int i, int n, SegmentTree& stree) {
    if (i == n - 1) return 0;
    stree.erase(p[i]);
    ll res = stree.count_smaller(p[i]) * (f[n - i - 1] + g[n - i]);
    res = (res + ans(i + 1, n, stree)) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    p.resize(n);
    for (auto& x : p) cin >> x;

    f.resize(n, 0), g.resize(n + 1);
    for (int i = 0; i <= n; i++)
        g[i] = (i + 1) / 2;
    for (int i = 2; i < n; i++)
        f[i] = (i * f[i - 1] + (i - 1) * g[i]) % MOD;

    SegmentTree stree(n);

    cout << ans(0, n, stree) << '\n';
    return 0;
}