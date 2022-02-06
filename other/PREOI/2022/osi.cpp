#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> link, set_size;
    DSU(int _n) : n(_n), link(n), set_size(n, 1) {
        iota(link.begin(), link.end(), 0);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (set_size[x] < set_size[y]) swap(x, y);
        set_size[x] += set_size[y];
        link[y] = x;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    auto w = [n](int x, int y){return y * n + x;};
    vector<pair<int,int>> to_add;
    vector<set<int>> complaint(n * m);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w1 = w(--x1, --y1),
            w2 = w(--x2, --y2);
        if (w1 > w2) swap(w1, w2);
        to_add.push_back({w1, w2});
        complaint[w1].insert(w2);
    }
    int r = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (x < n - 1 && complaint[w(x, y)].count(w(x+1, y)) == 0)
                r++, to_add.push_back({w(x, y), w(x+1, y)});
            if (y < m - 1 && complaint[w(x, y)].count(w(x, y+1)) == 0)
                r++, to_add.push_back({w(x, y), w(x, y+1)});
        }
    }
    reverse(to_add.begin(), to_add.end());
    vector<bool> res;
    DSU dsu(n * m);
    for (int i = 0; i < r; i++)
        dsu.unite(to_add[i].first, to_add[i].second);
    for (int i = r; i < r + k; i++)
        res.push_back(dsu.unite(to_add[i].first, to_add[i].second));
    reverse(res.begin(), res.end());
    for (auto b : res)
        cout << (b ? "NIE" : "TAK") << '\n';
    return 0;
}