#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int a, b, w;
    bool operator<(Edge x) {
        return w < x.w;
    }
};

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
    pair<int,int> unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (set_size[x] < set_size[y]) swap(x, y);
        pair<int,int> res = {set_size[x], set_size[y]};
        set_size[x] += set_size[y];
        link[y] = x;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = Edge({--a, --b, w});
    }
    sort(edges.begin(), edges.end());
    auto dsu = DSU(n);
    vector<Edge> mst_edges;
    vector<pair<int,int>> mst_sizes;
    vector<vector<pair<int,int>>> graph(n);
    for (auto e : edges) {
        if (dsu.find(e.a) != dsu.find(e.b)) {
            graph[e.a].push_back({e.b, e.w});
            graph[e.b].push_back({e.a, e.w});
            mst_edges.push_back(e);
            mst_sizes.push_back(dsu.unite(e.a, e.b));
        }
    }
    reverse(mst_edges.begin(), mst_edges.end());
    reverse(mst_sizes.begin(), mst_sizes.end());

    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        auto [a, b, w] = mst_edges[i];
        auto [x, y] = mst_sizes[i];
        res += (ll) x * y * w * 2;
    }
    cout << res << '\n';
    return 0;
}