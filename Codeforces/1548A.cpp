#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> graph;
vector<bool> safe;
int res = 0;

void eval(int v) {
    bool prev_s = safe[v];
    safe[v] = all_of(graph[v].begin(), graph[v].end(), [v](int u){return u < v;});
    res = res - prev_s + safe[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    graph.resize(n+1); safe.resize(n+1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for (int i = 1; i <= n; i++) eval(i);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1 || c == 2) {
            int u, v;
            cin >> u >> v;
            if (c == 1) {
                graph[u].insert(v);
                graph[v].insert(u);
            } else {
                graph[u].erase(v);
                graph[v].erase(u);
            }
            eval(u), eval(v);
        } else
            cout << res << '\n';
    }
    return 0;
}