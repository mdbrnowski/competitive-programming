#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n, m;
    vector<int> d;
    vector<bool> fixed;
    vector<vector<pair<int,int>>> graph;
    Graph(int _n) : n(1 << (1 + __lg(_n))), m(2 * n), d(m, 1), fixed(m, false), graph(m) {
        for (int i = 2 * n - 1; i > 1; i--)
            graph[i / 2].push_back({i, 0});
    }
    void add_measurement(int a, int b, vector<int>& deeper) {
        graph.push_back({});  // add imaginary vertex
        for (auto x : deeper)
            graph[n + x].push_back({m, 0});

        add_edges_to_vertex(a, deeper[0] - 1, m);
        for (int i = 0; i < (int) deeper.size() - 1; i++)
            add_edges_to_vertex(deeper[i] + 1, deeper[i + 1] - 1, m);
        add_edges_to_vertex(deeper.back() + 1, b, m);
        m++;
    }
    bool topological_sort() {
        d.resize(m, 0), fixed.resize(m, false);  // resize for imaginary vertices
        vector<int> visited(m, 0);  // 0 - unvisited, 1 - active, 2 - visited in the past
        return dfs(1, visited);  // we've previously created a tree, so it's enough to run the dfs only once
    }
    private:
    void add_edges_to_vertex(int a, int b, int c) {
        a += n, b += n;
        while (a <= b) {
            if ((a & 1) == 1) graph[c].push_back({a++, 1});
            if ((b & 1) == 0) graph[c].push_back({b--, 1});
            a /= 2, b /= 2;
        }
    }
    bool dfs(int v, vector<int>& visited) {
        if (visited[v]) return (visited[v] == 2);  // there is (not) a cycle
        visited[v] = 1;
        for (auto [u, w] : graph[v]) {
            if (!dfs(u, visited))
                return false;  // there is a contradiction
        }
        visited[v] = 2;

        int new_d = 0;
        for (auto [u, w] : graph[v])
            new_d = max(new_d, d[u] + w);
        if ((fixed[v] && new_d > d[v]) || new_d > 1e9) return false;
        d[v] = max(d[v], new_d);
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, m;
    cin >> n >> s >> m;
    auto G = Graph(n);
    for (int i = 0; i < s; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        G.d[x + G.n] = y;
        G.fixed[x + G.n] = true;
    }
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        vector<int> deeper(k);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            deeper[j] = --x;
        }
        G.add_measurement(--l, --r, deeper);
    }

    if (!G.topological_sort()) {
        cout << "NIE\n";
        return 0;
    } else cout << "TAK\n";

    for (int i = G.n; i < G.n + n; i++)
        cout << G.d[i] << ' ';
    cout << '\n';
    return 0;
}