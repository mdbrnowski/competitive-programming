#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
constexpr int neg(int x) { return x + (x % 2 ? 1 : -1); }

void dfs_1(int v, vvi& graph, vector<bool>& visited, stack<int>& s) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : graph[v])
        dfs_1(u, graph, visited, s);
    s.push(v);
}

void dfs_2(int v, int c, vvi& graph, vector<int>& scc) {
    if (scc[v] != -1) return;
    scc[v] = c;
    for (auto u : graph[v])
        dfs_2(u, c, graph, scc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int nn = 2 * n + 1;
    vvi graph_1(nn), graph_2(nn);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph_1[a].push_back(neg(b));
        graph_1[b].push_back(neg(a));
        graph_2[neg(b)].push_back(a);
        graph_2[neg(a)].push_back(b);
    }
    stack<int> s;
    vector<bool> visited(nn, false);
    for (int i = 1; i < nn; i++)
        dfs_1(i, graph_1, visited, s);
    int c = 0;
    vector<int> scc(nn, -1);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (scc[v] == -1)
            dfs_2(v, c++, graph_2, scc);
    }

    vector<int> res;
    for (int i = 1; i < nn; i += 2) {
        if (scc[i] == scc[i + 1]) {
            cout << "NIE\n";
            return 0;
        } else if (scc[i] < scc[i + 1])
            res.push_back(i + 1);
        else
            res.push_back(i);
    }
    for (auto x : res) cout << x << '\n';
    return 0;
}