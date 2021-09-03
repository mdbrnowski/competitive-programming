#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lsb(x) (x & -x)

struct fenwick_tree {
    int n;
    vector<int> tree;
    fenwick_tree(int size) : n(size), tree(n+1, 0) {}
    ll sum(int i) {
        ll res = 0;
        while (i > 0)
            res += tree[i], i -= lsb(i);
        return res;
    }
    ll range_sum(int a, int b) {
        return sum(b) - sum(a-1);
    }
    void add(int i, int x) {
        while (i <= n)
            tree[i] += x, i += lsb(i);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto ftree = fenwick_tree(n);
    ll cur_k = 0, res = 0;
    ftree.add(a[0], 1);
    for (int i = 0, j = 0; i <= j && j < n; i++) {
        while (j+1 < n && cur_k + ftree.range_sum(a[j+1]+1, n) <= k) {
            cur_k += ftree.range_sum(a[j+1]+1, n);
            ftree.add(a[j+1], 1);
            j++;
        }
        res += j - i + 1;
        cur_k -= ftree.range_sum(1, a[i] - 1);
        ftree.add(a[i], -1);
    }
    cout << res << '\n';
    return 0;
}