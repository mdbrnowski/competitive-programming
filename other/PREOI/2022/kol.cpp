#include <bits/stdc++.h>
using namespace std;

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

struct Forest {
    int n;
    DSU dsu = DSU({});
    vector<int> depth, dist;
    vector<vector<int>> ancestor;
    vector<vector<pair<int,int>>> graph;
    Forest(int _n) : n(_n), dsu(n), depth(n, 0), dist(n, 0), ancestor(n, vector<int>(20)), graph(n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 20; j++)
                ancestor[i][j] = i;
    }
    void add_edge(int a, int b, int w) {
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
        if (dsu.size[dsu.find(a)] < dsu.size[dsu.find(b)])
            swap(a, b);
        dsu.unite(a, b);
        merge(a, b, w);
    }
    int get_dist(int a, int b) {
        return dist[a] + dist[b] - 2 * dist[lca(a, b)];
    }

    private:
    void merge(int a, int b, int w) {
        dist[b] = dist[a] + w;
        vector<int> descendants = {b};
        dfs(b, a, descendants);
        for (int k = 1; k < 20; k++)
            for (auto i : descendants)
                ancestor[i][k] = ancestor[ancestor[i][k-1]][k-1];
    }
    void dfs(int v, int prev, vector<int>& descendants) {
        depth[v] = depth[prev] + 1;
        ancestor[v][0] = prev;
        for (auto [u, w] : graph[v]) {
            if (u != prev) {
                dist[u] = dist[v] + w;
                descendants.push_back(u);
                dfs(u, v, descendants);
            }
        }
    }
    int lca(int a, int b) {
        int res = 0;
        if (depth[a] > depth[b]) swap(a, b);
        for (int k = 19; k >= 0; k--) {
            if (depth[ancestor[b][k]] >= depth[a])
                b = ancestor[b][k];
        }
        if (a == b) return a;
        for (int k = 19; k >= 0; k--) {
            if (ancestor[a][k] != ancestor[b][k])
                a = ancestor[a][k],
                b = ancestor[b][k];
        }
        return ancestor[a][0];
    }
};

Forest F = Forest({});

void init(int N, int S) {
    F = Forest(N);
}

void build(int x, int y, int m) {
    F.add_edge(--x, --y, m);
}

int path(int x, int y)  {
    return F.get_dist(--x, --y);
}