#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll INF = 1e18;

void dijkstra(int s, vector<vector<pair<int,int>>>& graph, vector<ll>& dist) {
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(2 * n);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b + n, w});
        graph[b + n].push_back({a, w});
        graph[b].push_back({a + n, w});
        graph[a + n].push_back({b, w});
    }
    int Z, D;
    cin >> Z >> D;
    Z--, D--;
    vector<ll> dist(2 * n, INF);
    dijkstra(Z, graph, dist);
    cout << (dist[D] == INF ? -1 : dist[D]) << ' '
         << (dist[D + n] == INF ? -1 : dist[D + n]) << '\n';
    return 0;
}