#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> matched;
vector<bool> visited;

bool kuhn(int v) {
    if (visited[v]) return false;
    visited[v] = true;
    for (auto u : graph[v]) {
        if (matched[u] == -1 || kuhn(matched[u])) {
            matched[v] = u;
            matched[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.resize(n+m+1), matched.resize(n+m+1, -1), visited.resize(n+m+1, false);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while (true) {
        visited.assign(n+m+1, false);
        bool any = false;
        for (int i = 1; i <= n+m; i++)
            if (matched[i] == -1 && kuhn(i)) any = true;
        if (!any) break;
    }
    int res = 0;
    for (int i = 1; i <= n+m; i++)
        if (matched[i] > -1) res++;
    cout << n+m - res / 2 << '\n';
    return 0;
}