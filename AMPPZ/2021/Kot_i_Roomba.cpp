#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n, c;
        cin >> n >> c;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> parent(n + 1);
        function<void(int, int)> dfs = [&](int v, int prev) {
            for (auto u : graph[v])
                if (u != prev) {
                    parent[u] = v;
                    dfs(u, v);
                }
        };
        dfs(1, 1);

        int m;
        cin >> m;
        double res = 0;
        vector<double> p(n + 1, 0), for_children(n + 1, 0);
        p[c] = 1;
        while (m--) {
            int x;
            cin >> x;
            double val = p[x] + for_children[parent[x]];
            res += val;
            p[x] -= val;
            for_children[x] += val / sz(graph[x]);
            p[parent[x]] += val / sz(graph[x]);
        }

        cout << setprecision(16) << res << '\n';
    }
    return 0;
}
