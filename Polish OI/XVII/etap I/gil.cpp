#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<char> res;

void DFS(int x, bool g) {
    res[x] = g ? 'K' : 'S';
    for (auto v : graph[x]) {
        if (res[v] == 0)
            DFS(v, !g);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.resize(n+1), res.resize(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) {
            if (graph[i].empty()) {
                cout << "NIE\n";
                return 0;
            }
            DFS(i, 1);
        }
    }

    cout << "TAK\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
    return 0;
}