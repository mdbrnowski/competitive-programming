#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n), p(n);
        for (auto& x : b) cin >> x;
        for (auto& x : p) cin >> x;
        vector<vector<int>> graph(n+1);
        for (int i = 1; i <= n; i++)
            graph[b[i-1]].push_back(i);

        bool ok = true;
        vector<int> dist(n+1, INF);
        int max_dist = -1;
        unordered_set<int> avaible = {p[0]};
        for (auto v : p) {
            if (avaible.count(v) == 0) {
                cout << -1;
                ok = false;
                break;
            }
            dist[v] = ++max_dist;
            for (auto u : graph[v])
                if (dist[u] == INF)
                    avaible.insert(u);
        }
        if (ok) for (int i = 1; i <= n; i++)
            cout << dist[i] - dist[b[i-1]] << ' ';
        cout << '\n';
    }
    return 0;
}