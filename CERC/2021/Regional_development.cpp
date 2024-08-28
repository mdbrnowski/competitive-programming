#include <bits/stdc++.h>
using namespace std;

bool flow(int s, int t, int M, vector<unordered_map<int, int>>& graph) {
    queue<int> q;
    q.push(s);
    vector<int> parent(graph.size(), -1);
    parent[s] = s;
    while (q.size() && parent[t] == -1) {
        int v = q.front();
        q.pop();
        for (auto& [u, w] : graph[v]) {
            if (w && parent[u] == -1) {
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if (parent[t] == -1)
        return false;

    int v = t;
    while (parent[v] != v) {
        graph[parent[v]][v] -= M;
        if (graph[parent[v]][v] < 0) {
            graph[v][parent[v]] = -graph[parent[v]][v];
            graph[parent[v]][v] = 0;
        }
        v = parent[v];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, R, M;
    cin >> N >> R >> M;
    vector<pair<int, int>> for_return(R);
    vector<unordered_map<int, int>> graph(N + 2);
    for (auto& [a, b] : for_return) {
        int c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = 0;
    }

    int SOURCE = 0, SINK = N + 1;
    for (int v = 1; v <= N; v++) {
        int in = 0, out = 0;
        for (auto [u, w] : graph[v]) {
            if (w)
                out += w;
            else
                in += graph[u][v];
        }
        if (in - out > 0)
            graph[SINK][v] = 0, graph[v][SINK] = in - out;
        if (out - in > 0)
            graph[SOURCE][v] = out - in, graph[v][SOURCE] = 0;
    }

    while (flow(SOURCE, SINK, M, graph));

    for (auto [a, b] : for_return) {
        if (graph[a][b])
            cout << graph[a][b] << '\n';
        else
            cout << -graph[b][a] << '\n';
    }
    return 0;
}
