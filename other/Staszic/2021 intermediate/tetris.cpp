#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int n;
    vector<int> tree;
    vector<bool> lazy;
    segment_tree(int _n) : n(1 << (1 + __lg(_n))), tree(2*n, 0), lazy(2*n, false) {}
    void assign(int a, int b, int x, int k, int ka, int kb) {
        if (b < ka || a > kb) return;
        if (a <= ka && b >= kb) {
            tree[k] = x;
            lazy[k] = true;
            return;
        }
        push(k);
        int d = (ka + kb) / 2;
        assign(a, b, x, 2*k, ka, d);
        assign(a, b, x, 2*k+1, d+1, kb);
        tree[k] = max(tree[2*k], tree[2*k+1]);
    }
    int range_max(int a, int b, int k, int ka, int kb) {
        if (b < ka || a > kb) return 0;
        if (a <= ka && b >= kb) return tree[k];
        push(k);
        int d = (ka + kb) / 2;
        return max(range_max(a, b, 2*k, ka, d), range_max(a, b, 2*k+1, d+1, kb));
    }
    private:
    void push(int i) {
        if (lazy[i]) {
            lazy[i] = false;
            tree[i*2] = tree[i*2+1] = tree[i];
            lazy[i*2] = lazy[i*2+1] = true;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int d, n;
    cin >> d >> n;
    auto stree = segment_tree(d);
    while (n--) {
        int l, x;
        cin >> l >> x;
        int m = stree.range_max(x, x+l-1, 1, 0, stree.n-1);
        stree.assign(x, x+l-1, m+1, 1, 0, stree.n-1);
    }
    cout << stree.range_max(0, d-1, 1, 0, stree.n-1) << '\n';
    return 0;
}