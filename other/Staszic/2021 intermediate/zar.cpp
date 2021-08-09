#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int n;
    vector<bool> tree;
    segment_tree(string s) : n(1 << (1 + __lg(s.size()))), tree(2*n, 0) {
        tree[n] = (s[0] == 'x' ? 0 : 1);
        for (int i = 1; i < s.size(); i++)
            tree[n+i] = (s[i] == s[i-1] ? 0 : 1);
        for (int i = n-1; i > 0; i--)
            tree[i] = tree[i<<1] ^ tree[(i<<1) + 1];
    }
    void switch_point(int i) {
        i += n;
        tree[i] = !tree[i];
        for (i >>= 1; i > 0; i >>= 1)
            tree[i] = tree[i<<1] ^ tree[(i<<1) + 1];
    }
    void switch_range(int a, int b) {
        switch_point(a);
        switch_point(b+1);
    }
    bool query(int b) {
        b += n; int a = n;
        int res = 0;
        while (a <= b) {
            if ((a&1) == 1) res ^= tree[a++];
            if ((b&1) == 0) res ^= tree[b--];
            a >>= 1, b >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; string s;
    cin >> n >> m >> s;
    auto stree = segment_tree(s);
    while (m--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int q;
            cin >> q;
            cout << (stree.query(q-1) ? "ON" : "OFF") << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            stree.switch_range(a-1, b-1);
        }
    }
    return 0;
}