#include <bits/stdc++.h>
using namespace std;

vector<multiset<int>> graph;
vector<set<int>> tree;  // of biconnected components

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
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (set_size[x] < set_size[y]) swap(x, y);
        set_size[x] += set_size[y];
        link[y] = x;
    }
};

void dfs_b(int v, int prev, int& timer, vector<bool>& visited, vector<int>& d, vector<int>& low, bool& bridge, DSU& bcc) {
    visited[v] = true;
    d[v] = low[v] = timer++;
    for (int u : graph[v]) {
        if (u == prev) continue;
        if (visited[u])
            low[v] = min(low[v], d[u]);
        else {
            dfs_b(u, v, timer, visited, d, low, bridge, bcc);
            low[v] = min(low[v], low[u]);
            if (low[u] > d[v] && graph[v].count(u) == 1)
                bridge = true;
            else
                bcc.unite(u, v);
        }
    }
}

bool find_bridges(int n, DSU& bcc) {
    int timer = 0;
    vector<bool> visited(n, false);
    vector<int> d(n, -1), low(n, -1);
    bool bridge = false;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs_b(i, -1, timer, visited, d, low, bridge, bcc);
    }
    return bridge;
}

pair<int,int> dfs(int v, int d, vector<bool>& visited) {
    visited[v] = true;
    pair<int,int> res = {d, v};
    for (auto u : tree[v]) {
        if (visited[u]) continue;
        res = max(res, dfs(u, d + 1, visited));
    }
    return res;
}

tuple<int,int,int> calc_diameter(int n) {
    vector<bool> visited(n, false);
    vector<pair<int,int>> farthests;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            farthests.push_back(dfs(i, 0, visited));

    visited.assign(n, false);
    tuple<int,int,int> res = {0, 0, 0};
    for (auto [dist, v] : farthests) {
        auto [d, u] = dfs(v, 0, visited);
        res = max(res, {d, u, v});
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.resize(n), tree.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    DSU bcc(n);  // biconnected components
    bool bridge = find_bridges(n, bcc);
    if (!bridge) {
        cout << 0 << ' ';
        for (int i = 0; i < n; i++) {
            if (!graph[i].empty()) {
                cout << i + 1 << ' ' << *graph[i].begin() + 1 << '\n';
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto x : graph[i]) {
            if (bcc.find(i) == bcc.find(x)) continue;
            tree[bcc.find(i)].insert(bcc.find(x));
            tree[bcc.find(x)].insert(bcc.find(i));
        }
    }
    auto [k, s, t] = calc_diameter(n);
    cout << k << ' ' << s + 1 << ' ' << t + 1 << '\n';
    return 0;
}