#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct DSU {
    int n;
    vi link, size;
    DSU(int _n) : n(_n), link(n+1), size(n+1, 1) {
        iota(link.begin(), link.end(), 0);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        link[y] = x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void dijkstra(int s, vector<vector<pii>>& graph, vector<ll>& dist) {
    priority_queue<pair<ll,int>> q;
    vector<bool> processed(graph.size(), false);
    dist[s] = 0;
    q.push({0, s});
    while (q.size()) {
        int v = q.top().second; q.pop();
        if (processed[v]) continue;
        processed[v] = true;
        for (auto [u, w] : graph[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                q.push({-dist[u], u});
            }
        }
    }
}

struct Edge {
    ll c; int v, u;
    bool operator<(Edge other) { return c < other.c; }
};

struct Query {
    int x, y, b, id;
    bool operator<(Query other) { return b < other.b; }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, m;
    cin >> n >> s >> m;
    vi S(s);
    for (auto& c : S) cin >> c;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }
    for (auto c : S)
        graph[0].push_back({c, 0});

    vector<ll> ds(n+1, 1e18);  // distance to the closest station
    dijkstra(0, graph, ds);

    vector<Edge> edges;
    for (int v = 1; v <= n; v++) {
        for (auto [u, d] : graph[v])
            if (v < u) {
                auto e = Edge{ds[u] + ds[v] + d, u, v};
                edges.push_back(e);
            }
    }
    sort(edges.begin(), edges.end());

    int q;
    cin >> q;
    vector<bool> res(q);
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].x >> queries[i].y >> queries[i].b;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());

    auto dsu = DSU(n);
    int i = 0;
    for (auto qu : queries) {
        while (i < m && edges[i].c <= qu.b) {
            dsu.unite(edges[i].v, edges[i].u);
            i++;
        }
        res[qu.id] = dsu.same(qu.x, qu.y);
    }

    for (auto r : res)
        cout << (r ? "TAK" : "NIE") << '\n';
    return 0;
}