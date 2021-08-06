#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int n;
    vector<int> tree;
    segment_tree(vector<int> arr) : n(1 << (1 + __lg(arr.size()))), tree(2*n, 0) {
        for (int i = 0; i < arr.size(); i++)
            tree[n+i] = arr[i];
        for (int i = n-1; i > 0; i--)
            tree[i] = tree[i<<1] ^ tree[(i<<1)+1];
    }
    void update(int i, int x) {
        i += n;
        tree[i] = x;
        for (i >>= 1; i > 0; i >>= 1)
            tree[i] = tree[i<<1] ^ tree[(i<<1)+1];
    }
    void swap(int a, int b) {
        int v_a = tree[a+n], v_b = tree[b+n];
        update(a, v_b);
        update(b, v_a);
    }
    int range(int a, int b) {
        a += n, b += n;
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    auto stree = segment_tree(arr);
    while (q--) {
        string o; int a, b;
        cin >> o >> a >> b;
        if (o == "zamien")
            stree.swap(a-1, b-1);
        else
            cout << stree.range(a-1, b-1) << '\n';
    }
    return 0;
}