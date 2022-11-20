#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Isl {
    int x, y, id;
    int operator-(Isl other) {
        return min(abs(x - other.x), abs(y - other.y));
    }
};

ll dijkstra(int s, vector<vector<pii>>& graph) {
    priority_queue<pair<ll,int>> q;
    vector<ll> dist(graph.size(), 1e18);
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
    return dist.back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Isl> isls(n);
    for (int i = 0; i < n; i++) {
        cin >> isls[i].x >> isls[i].y;
        isls[i].id = i;
    }

    auto islsX = isls, islsY = isls;
    sort(islsX.begin(), islsX.end(), [](Isl a, Isl b){ return a.x < b.x; });
    sort(islsY.begin(), islsY.end(), [](Isl a, Isl b){ return a.y < b.y; });

    vector<vector<pii>> graph(n);
    for (int i = 1; i < n; i++) {
        auto a = islsX[i], b = islsX[i-1];
        int w = a - b;
        graph[a.id].push_back({b.id, w});
        graph[b.id].push_back({a.id, w});
    }
    for (int i = 1; i < n; i++) {
        auto a = islsY[i], b = islsY[i-1];
        int w = a - b;
        graph[a.id].push_back({b.id, w});
        graph[b.id].push_back({a.id, w});
    }

    cout << dijkstra(0, graph) << '\n';
    return 0;
}
