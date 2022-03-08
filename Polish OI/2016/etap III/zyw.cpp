#include <bits/stdc++.h>
using namespace std;

#define w(i, j) ((i) * n + (j))

struct Edge {
    int u, v;
    bool ver, yew;
};

struct DSU {
    int n;
    vector<int> link, size;
    DSU(int _n) : n(_n), link(n), size(n, 1) {
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
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        link[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int res = m * (n - 1) + (m - 1) * n, res_yew = 0;
    deque<Edge> edges;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            char c;
            cin >> c;
            if (c == 'C')
                edges.push_back(Edge{w(i, j), w(i, j + 1), true, true}),
                res_yew++;
            else
                edges.push_front(Edge{w(i, j), w(i, j + 1), true, false});
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'C')
                edges.push_back(Edge{w(i, j), w(i + 1, j), false, true}),
                res_yew++;
            else
                edges.push_front(Edge{w(i, j), w(i + 1, j), false, false});
        }
    }
    DSU dsu(n * m);
    vector<bool> fence_ver(m * n, true), fence_hor(m * n, true);
    for (auto [u, v, ver, yew] : edges) {
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u, v);
        res -= 1;
        res_yew -= yew;
        if (ver)
            fence_ver[u] = false;
        else
            fence_hor[u] = false;
    }

    cout << res << ' ' << res_yew << '\n';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++)
            cout << (fence_ver[w(i, j)] ? 'Z' : '.');
        cout << '\n';
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++)
            cout << (fence_hor[w(i, j)] ? 'Z' : '.');
        cout << '\n';
    }
    return 0;
}