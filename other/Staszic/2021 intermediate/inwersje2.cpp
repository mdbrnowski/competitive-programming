#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lsb(x) (x & -x)

struct fenwick_tree {
    int n;
    vector<ll> tree;
    fenwick_tree(int size) : n(size), tree(n+1, 0) {};
    ll sum(int i) {
        ll res = 0;
        while (i > 0)
            res += tree[i], i -= lsb(i);
        return res;
    }
    void add(int i, int x) {
        while (i <= n)
            tree[i] += x, i += lsb(i);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> mapper(a.begin(), a.end());
    sort(mapper.begin(), mapper.end());
    mapper.resize(unique(mapper.begin(), mapper.end()) - mapper.begin());
    for (auto& x : a)
        x = lower_bound(mapper.begin(), mapper.end(), x) - mapper.begin() + 1;

    auto ftree = fenwick_tree(n);
    int res = 0;
    for (int i = n-1; i >= 0; i--) {
        res += ftree.sum(a[i] - 1);
        ftree.add(a[i], 1);
    }
    cout << res << '\n';
    return 0;
}