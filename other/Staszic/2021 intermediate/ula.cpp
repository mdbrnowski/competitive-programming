#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs_1(int v, vvi& graph, vb& visited, stack<int>& s) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : graph[v])
        dfs_1(u, graph, visited, s);
    s.push(v);
}

void dfs_2(int v, int c, vvi& graph, vi& scc) {
    if (scc[v] != -1) return;
    scc[v] = c;
    for (auto u : graph[v])
        dfs_2(u, c, graph, scc);
}

void dfs_3(int v, vector<set<int>>& graph, vi& scc_points, vi& res, int score = 0) {
    score += scc_points[v];
    if (score <= res[v]) return;
    res[v] = score;
    for (auto u : graph[v])
        dfs_3(u, graph, scc_points, res, score);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi points(n+1);
    for (int i = 1; i <= n; i++) cin >> points[i];
    vvi graph_1(n+1), graph_2(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph_1[a].push_back(b);
        graph_2[b].push_back(a);
    }
    stack<int> s;
    vb visited(n+1);
    for (int i = 1; i <= n; i++)
        dfs_1(i, graph_1, visited, s);

    int c = 0;
    vi scc(n+1, -1);
    while (!s.empty()) {
        int v = s.top(); s.pop();
        if (scc[v] == -1)
            dfs_2(v, c++, graph_2, scc);
    }

    vi scc_points(c, 0);
    for (int i = 1; i <= n; i++)
        scc_points[scc[i]] += points[i];

    vb zero_indegree(c, true);
    vector<set<int>> dag(c);
    for (int v = 1; v <= n; v++) {
        for (auto u : graph_1[v]) {
            if (scc[v] != scc[u]) {
                dag[scc[v]].insert(scc[u]);
                zero_indegree[scc[u]] = false;
            }
        }
    }

    vi res(c, 0);
    for (int i = 0; i < c; i++)
        if (zero_indegree[i])
            dfs_3(i, dag, scc_points, res);
    cout << *max_element(res.begin(), res.end()) << '\n';
    return 0;
}