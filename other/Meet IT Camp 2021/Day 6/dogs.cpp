#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll INF = 1e18;

int n, m;
vector<vector<pair<int,int>>> graph;

void dijkstra(int s, vector<ll>& distance) {
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll,int>> q;
    distance[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second; q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        for (auto uw : graph[v]) {
            int u, w; tie(u, w) = uw;
            if (distance[v] + w < distance[u]) {
                distance[u] = distance[v] + w;
                q.push({-distance[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n+1);
    vector<int> dog(3);
    for (auto& x : dog) cin >> x;
    for (int i = 0; i < m; i++) {
        int v, u, t;
        cin >> v >> u >> t;
        graph[v].push_back({u, t});
        graph[u].push_back({v, t});
    }
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for (int i = 1; i <= n; i++) dijkstra(i, dist[i]);
    int q;
    cin >> q;
    vector<int> qs(q);
    for (auto& x : qs) cin >> x;
    vector<vector<ll>> dp_prev(n+1, vector<ll>(n+1, INF)), dp(n+1, vector<ll>(n+1, INF));
    dp[dog[0]][dog[1]] = dp[dog[1]][dog[0]] = dist[dog[2]][qs[0]];
    dp[dog[0]][dog[2]] = dp[dog[2]][dog[0]] = dist[dog[1]][qs[0]];
    dp[dog[1]][dog[2]] = dp[dog[2]][dog[1]] = dist[dog[0]][qs[0]];

    for (int k = 1; k < q; k++) {
        swap(dp, dp_prev);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll mini = dp_prev[i][j] + dist[qs[k-1]][qs[k]];
                if (i == qs[k-1])
                    for (int g = 1; g <= n; g++)
                        mini = min(mini, dp_prev[j][g] + dist[g][qs[k]]);
                if (j == qs[k-1])
                    for (int g = 1; g <= n; g++)
                        mini = min(mini, dp_prev[i][g] + dist[g][qs[k]]);
                dp[i][j] = dp[j][i] = mini;
            }
        }
    }

    ll res = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = min(res, dp[i][j]);

    cout << (res < INF ? res : -1) << '\n';
    return 0;
}