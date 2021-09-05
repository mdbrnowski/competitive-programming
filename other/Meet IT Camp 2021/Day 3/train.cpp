#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll INF = 1e16;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(2*n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c}), graph[b].push_back({a, c});
        graph[a+n].push_back({b+n, c}), graph[b+n].push_back({a+n, c});
        graph[a].push_back({b+n, 1}), graph[b].push_back({a+n, 1});
    }
    vector<ll> distance(2*n+1, INF);
    vector<bool> visited(2*n+1, false);
    priority_queue<pair<ll,int>> q;
    distance[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int v = q.top().second; q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        for (auto u_w : graph[v]) {
            int u = u_w.first; int w = u_w.second;
            if (distance[v] + w < distance[u]) {
                distance[u] = distance[v] + w;
                q.push({-distance[u], u});
            }
        }
    }
    cout << (distance[2*n] == INF ? "NOPE" : "DOGE IS HAPPY") << '\n';
    if (distance[2*n] != INF) cout << distance[2*n] << '\n';
    return 0;
}