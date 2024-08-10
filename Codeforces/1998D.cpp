#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph) {
    vector<int> dist(graph.size(), -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v]) {
            if (dist[u] != -1)
                continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int i = 1; i < n; i++)
            graph[i].push_back(i + 1);

        vector<pair<int, int>> bridges(m);
        for (auto& [a, b] : bridges) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        auto dist = bfs(graph);
        vector<int> open(n + 1, 0);
        for (auto [a, b] : bridges) {
            if (a + 1 < b - (dist[a] + 1)) {
                open[a + 1] += 1;
                open[b - (dist[a] + 1)] -= 1;
            }
        }
        partial_sum(open.begin(), open.end(), open.begin());
        for (int i = 1; i < n; i++)
            cout << (open[i] == 0);
        cout << '\n';
    }
    return 0;
}
