#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs_1(int v, const vvi& graph, vi& visited, stack<int>& s) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : graph[v])
        dfs_1(u, graph, visited, s);
    s.push(v);
}

void dfs_2(int v, int c, const vvi& graph, vi& scc) {
    if (scc[v] != -1) return;
    scc[v] = c;
    for (auto u : graph[v])
        dfs_2(u, c, graph, scc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n, m, k;
        cin >> n >> m;
        vvi graph_1(n+1), graph_2(n+1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph_1[a].push_back(b);
            graph_2[b].push_back(a);
        }
        vi visited(n+1, false);
        stack<int> s;
        for (int i = 1; i <= n; i++)
            dfs_1(i, graph_1, visited, s);
        int c = 0;
        vi scc(n+1, -1);
        while (!s.empty()) {
            int v = s.top(); s.pop();
            if (scc[v] == -1)
                dfs_2(v, c++, graph_2, scc);
        }
        cin >> k;
        while (k--) {
            int u, v;
            cin >> u >> v;
            cout << (scc[u] == scc[v] ? "TAK" : "NIE") << '\n';
        }
    }
    return 0;
}