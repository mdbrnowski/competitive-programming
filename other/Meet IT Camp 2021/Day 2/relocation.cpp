#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    int n;
    vector<int> link, set_size;
    disjoint_set_union(int _n) : n(_n), link(n+1), set_size(n+1, 1) {
        iota(link.begin(), link.end(), 0);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (set_size[x] < set_size[y]) swap(x, y);
        set_size[x] += set_size[y];
        link[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    auto dsu = disjoint_set_union(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dsu.find(p[i-1]) == dsu.find(i)) res++;
    cout << res << '\n';
    return 0;
}