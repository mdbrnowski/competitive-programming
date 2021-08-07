#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int n;
    vector<vector<int>> tree;
    segment_tree(int a) : n(1 << (1 + __lg(a))), tree(6, vector<int>(2*n, 0)) {
        for (int i = a; i < n; i++) tree[0][n+i] = 1e9+7;   // prime
        for (int k = 1; k <= 5; k++) {
            for (int i = 0; i < n; i++)
                tree[k][n+i] = (tree[0][n+i] % k == 0);
            for (int i = n-1; i > 0; i--)
                tree[k][i] = tree[k][i<<1] + tree[k][(i<<1) + 1];
        }
    }
    void add(int i, int x) {
        i += n;
        tree[0][i] += x;
        for (int k = 1; k <= 5; k++) {
            tree[k][i] = (tree[0][i] % k == 0);
            for (int j = i >> 1; j > 0; j >>= 1)
                tree[k][j] = tree[k][j<<1] + tree[k][(j<<1) + 1];
        }
    }
    int range(int l, int r, int k) {
        int res = 0;
        l += n, r += n;
        while (l <= r) {
            if ((l & 1) == 1) res += tree[k][l++];
            if ((r & 1) == 0) res += tree[k][r--];
            l >>= 1, r >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    auto stree = segment_tree(n);
    while (q--) {
        string s;
        cin >> s;
        if (s == "DODAJ") {
            int p, c;
            cin >> p >> c;
            stree.add(p-1, c);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << stree.range(l-1, r-1, k) << '\n';
        }
    }
    return 0;
}