#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

void dfs(int v, int prev, vector<set<int>>& graph, vi& parent) {
    for (auto u : graph[v]) {
        if (u != prev && parent[u] == -1) {
            parent[u] = v;
            dfs(u, v, graph, parent);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> graph(n+1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        bool ok = false;
        for (int v = 1; v <= n; v++) {
            if (sz(graph[v]) < 4) continue;
            vi parent(n+1, -1);
            dfs(v, v, graph, parent);
            if (parent[v] != -1) {
                ok = true;
                vi path = {v};
                int c1 = parent[v], c2 = v;
                while (parent[c2] != v) {
                    path.push_back(parent[c2]);
                    c2 = parent[c2];
                }
                int c3, c4;
                for (auto c : graph[v]) {
                    if (c != c1 && c != c2) {
                        auto it = find(path.begin(), path.end(), c);
                        if (it != path.end()) {
                            path.resize(it - path.begin() + 1);
                            c3 = c2; c2 = c;
                        } else c3 = c;
                        break;
                    }
                }
                for (auto c : graph[v]) {
                    if (c != c1 && c != c2 && c != c3) {
                        auto it = find(path.begin(), path.end(), c);
                        if (it != path.end()) {
                            path.resize(it - path.begin() + 1);
                            c4 = c2; c2 = c;
                        } else c4 = c;
                        break;
                    }
                }
                cout << "YES\n";
                cout << sz(path) + 2 << '\n';
                for (int i = 0; i < sz(path)-1; i++)
                    cout << path[i] << ' ' << path[i+1] << '\n';
                cout << path.back() << ' ' << path[0] << '\n';
                cout << v << ' ' << c3 << '\n';
                cout << v << ' ' << c4 << '\n';
                break;
            }
        }
        if (!ok)
            cout << "NO\n";
    }
    return 0;
}
