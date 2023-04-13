#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool bipartite(int v, vector<vi>& graph, vi& color) {
    for (auto u : graph[v]) {
        if (color[u] > -1 && color[v] == color[u])
            return false;
        if (color[u] == -1) {
            color[u] = !color[v];
            if (!bipartite(u, graph, color))
                return false;
        }
    }
    return true;
}

bool solve() {
    int n;
    cin >> n;
    vector<vi> tiles(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tiles[a-1].push_back(i);
        tiles[b-1].push_back(i);
    }
    vector<vi> graph(n);
    for (auto c : tiles) {
        if (size(c) != 2 || c[0] == c[1])
            return false;
        graph[c[0]].push_back(c[1]);
        graph[c[1]].push_back(c[0]);
    }
    vi color(n, -1);
    bool res = true;
    for (int i = 0; i < n; i++)
        if (color[i] == -1) {
            color[i] = 0;
            res &= bipartite(i, graph, color);
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}
