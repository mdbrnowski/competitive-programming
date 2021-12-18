#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    int extra = 0;
    multiset<int> sizes;
    vector<int> link, set_size;
    DSU(int _n) : n(_n), link(n+1), set_size(n+1, 1) {
        iota(link.begin(), link.end(), 0);
        for (int i = 1; i <= n; i++)
            sizes.insert(1);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            extra++;
            return;
        }
        if (set_size[x] < set_size[y]) swap(x, y);
        sizes.erase(sizes.find(set_size[x]));
        sizes.erase(sizes.find(set_size[y]));
        set_size[x] += set_size[y];
        link[y] = x;
        sizes.insert(set_size[x]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    DSU dsu(n);
    while (d--) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
        int res = 0;
        auto it = dsu.sizes.rbegin();
        for (int i = 0; i < dsu.extra + 1; i++, it++)
            res += *it;
        cout << res - 1 << '\n';
    }
    return 0;
}