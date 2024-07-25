#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int v, int prev, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d,
         vector<int>& low, int& timer, vector<int>& results) {
    visited[v] = true;
    d[v] = low[v] = timer++;
    for (int u : graph[v]) {
        if (u == prev) continue;
        if (visited[u])
            low[v] = min(low[v], low[u]);
        else {
            dfs(u, v, graph, visited, d, low, timer, results);
            low[v] = min(low[v], low[u]);
            if (low[u] > d[v])
                results.push_back(timer - d[u]);  // size of a subtree
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);
        vector<int> d(n + 1, -1), low(n + 1, -1), results;
        int timer = 0;
        dfs(1, 0, graph, visited, d, low, timer, results);

        ll res = n * (n - 1) / 2;
        for (ll x : results)
            res = min(res, x * (x - 1) / 2 + (n - x) * (n - x - 1) / 2);
        cout << res << '\n';
    }
    return 0;
}
