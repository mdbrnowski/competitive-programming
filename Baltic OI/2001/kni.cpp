#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> deleted, visited;
vector<int> matched;
constexpr pair<int,int> SQUARES[] = {{-2,-1}, {-1,-2}, {-2,1}, {-1,2}, {2,-1}, {1,-2}, {2,1}, {1,2}};

void add_squares(int x, int y, int n) {
    for (auto d : SQUARES) {
        int dx = d.first, dy = d.second;
        if (x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n && !deleted[(x+dx)*n+y+dy])
            graph[x*n+y].push_back((x+dx)*n+y+dy);
    }
}

bool kuhn(int v) {
    if (visited[v]) return false;
    visited[v] = true;
    for (auto u : graph[v]) {
        if (matched[u] == -1 || kuhn(matched[u])) {
            matched[u] = v, matched[v] = u;
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
    graph.resize(n*n), deleted.resize(n*n, 0), visited.resize(n*n, 0), matched.resize(n*n, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        deleted[(x-1)*n+y-1] = true;
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            if (!deleted[x*n+y]) add_squares(x, y, n);
    }

    while (true) {
        visited.assign(n*n, false);
        bool any = false;
        for (int i = 1; i <= n*n; i++)
            if (matched[i] == -1 && kuhn(i)) any = true;
        if (!any) break;
    }

    int res = 0;
    for (int i = 0; i < n*n; i ++)
        if (matched[i] != -1) res++;
    cout << n*n - m - res/2;
    return 0;
}