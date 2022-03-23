#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9+7;

struct Query {
    int s, t, d;
};

void bfs(int start, int n, vector<vector<int>>& graph, set<int> in_queries, map<int,int>& dist) {
    vector<int> d(2 * n, INF);
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (auto u : graph[v])
            if (d[u] == INF) {
                d[u] = d[v] + 1;
                if (in_queries.count(u))
                    dist[u] = d[u];
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(2 * n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b + n);
        graph[b].push_back(a + n);
        graph[a + n].push_back(b);
        graph[b + n].push_back(a);
    }

    vector<Query> queries(k);
    vector<set<int>> in_queries(n);
    map<int,map<int,int>> dist;

    for (int i = 0; i < k; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        s--, t--;
        if (d % 2 == 1)
            t += n;
        queries[i] = Query{s, t, d};
        in_queries[s].insert(t);
    }

    for (int i = 0; i < n; i++)
        bfs(i, n, graph, in_queries[i], dist[i]);

    for (auto [s, t, d] : queries)
        if (s == t)
            cout << (graph[s].size() ? "TAK" : "NIE") << '\n';
        else
            cout << (dist[s].count(t) && dist[s][t] <= d ? "TAK" : "NIE") << '\n';

    return 0;
}