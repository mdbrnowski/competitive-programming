#include <bits/stdc++.h>
using namespace std;

bool bipartite(int v, int c, vector<vector<int>>& graph, vector<int>& color) {
    if (color[v] > -1)
        return color[v] == c;
    color[v] = c;
    for (auto u : graph[v]) {
        if (bipartite(u, c % 2 + 1, graph, color) == false)
            return false;
    }
    return true;
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
        while (m--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> color(n + 1, -1);
        if (bipartite(1, 1, graph, color)) {
            cout << "Bob" << endl;
            int a, b;
            array<vector<int>, 3> verts;
            for (int i = 1; i <= n; i++)
                verts[color[i]].push_back(i);
            for (int round = 0; round < n; round++) {
                cin >> a >> b;
                if (!verts[1].empty() && (a == 1 || b == 1)) {
                    cout << verts[1].back() << ' ' << 1 << endl;
                    verts[1].pop_back();
                } else if (!verts[2].empty() && (a == 2 || b == 2)) {
                    cout << verts[2].back() << ' ' << 2 << endl;
                    verts[2].pop_back();
                } else {
                    // only one of verts[1] and verts[2] is empty
                    for (int c : {1, 2}) {
                        if (!verts[c].empty()) {
                            cout << verts[c].back() << ' ' << 3 << endl;
                            verts[c].pop_back();
                        }
                    }
                }
            }
        } else {
            cout << "Alice" << endl;
            int i, c;
            for (int round = 0; round < n; round++) {
                cout << 1 << ' ' << 2 << endl;
                cin >> i >> c;
            }
        }
    }
    return 0;
}
