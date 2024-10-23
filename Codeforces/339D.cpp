#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(const vector<int>& a) : n(sz(a)), tree(2 * n, 0) {
        for (int i = 0; i < sz(a); i++)
            tree[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) {
            if (__lg(i) % 2 == __lg(n) % 2)
                tree[i] = tree[2 * i] ^ tree[2 * i + 1];
            else
                tree[i] = tree[2 * i] | tree[2 * i + 1];
        }
    }
    void update(int i, int x) {
        i += n;
        tree[i] = x;
        for (i /= 2; i > 0; i /= 2) {
            if (__lg(i) % 2 == __lg(n) % 2)
                tree[i] = tree[2 * i] ^ tree[2 * i + 1];
            else
                tree[i] = tree[2 * i] | tree[2 * i + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    n = 1 << n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    SegmentTree stree(a);
    while (m--) {
        int p, b;
        cin >> p >> b;
        stree.update(p - 1, b);
        cout << stree.tree[1] << '\n';
    }
    return 0;
}
