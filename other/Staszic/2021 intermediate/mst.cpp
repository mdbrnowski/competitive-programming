#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, w, id;
    bool operator<(const edge x) const {
        return w > x.w;
    }
};

struct DSU {
    int n;
    vector<int> link, size;
    DSU(int _n) : n(_n), link(n+1), size(n+1, 1) {
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
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        link[y] = link[x];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<edge> graph;
    vector<edge> mst;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.push(edge{a, b, w, i});
    }
    DSU dsu(n);
    while (!graph.empty()) {
        edge e = graph.top();
        if (dsu.unite(e.a, e.b))
            mst.push_back(e);
        graph.pop();
    }
    for (auto e : mst)
        cout << e.id << '\n';
    return 0;
}