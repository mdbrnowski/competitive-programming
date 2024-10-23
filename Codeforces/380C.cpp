#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;
#define sz(x) (int)(x).size()

iii merge(iii a, iii b) {
    int pairs = get<0>(a) + get<0>(b);
    int open = get<1>(a) + get<1>(b);
    int close = get<2>(a) + get<2>(b);
    int new_pairs = min(get<1>(a), get<2>(b));
    return {pairs + new_pairs, open - new_pairs, close - new_pairs};
}

struct SegmentTree {
    int n;
    vector<iii> tree;
    SegmentTree(const string& a) : n(1 << (1 + __lg(sz(a)))), tree(2 * n) {
        for (int i = 0; i < sz(a); i++) {
            if (a[i] == '(')
                tree[n + i] = {0, 1, 0};
            else
                tree[n + i] = {0, 0, 1};
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }
    int query(int l, int r) {
        l += n, r += n;
        vector<iii> to_left;
        vector<iii> to_right;
        while (l <= r) {
            if (l % 2 == 1)
                to_left.push_back(tree[l++]);
            if (r % 2 == 0)
                to_right.push_back(tree[r--]);
            l /= 2, r /= 2;
        }
        iii res = {0, 0, 0};
        reverse(to_left.begin(), to_left.end());
        reverse(to_right.begin(), to_right.end());
        for (auto x : to_left)
            res = merge(x, res);
        for (auto x : to_right)
            res = merge(res, x);
        return get<0>(res);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    SegmentTree stree(s);
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << 2 * stree.query(l - 1, r - 1) << '\n';
    }
    return 0;
}
