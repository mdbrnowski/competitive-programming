#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs_1(int v, const vvi& graph, vi& visited, stack<int>& s) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : graph[v])
        dfs_1(u, graph, visited, s);
    s.push(v);
}

void dfs_2(int v, int c, const vvi& graph, vi& scc) {
    if (scc[v] != -1) return;
    scc[v] = c;
    for (auto u : graph[v])
        dfs_2(u, c, graph, scc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vvi graph_1(n+1), graph_2(n+1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            while (a--) {
                int j;
                cin >> j;
                graph_1[j].push_back(i);
                graph_2[i].push_back(j);
            }
        }
        vi visited(n+1, false);
        stack<int> s;
        for (int i = 1; i <= n; i++)
            dfs_1(i, graph_1, visited, s);
        int c = 0;
        vi scc(n+1, -1);
        while (!s.empty()) {
            int v = s.top(); s.pop();
            if (scc[v] == -1)
                dfs_2(v, c++, graph_2, scc);
        }

        vector<int> size_of_scc(c, 0);
        for (int i = 1; i <= n; i++)
            size_of_scc[scc[i]]++;
        for (int i = 1; i <= n; i++)
            for (auto j : graph_1[i])
                if (scc[i] != scc[j])
                    size_of_scc[scc[j]] = INT_MAX;

        auto res = min_element(size_of_scc.begin(), size_of_scc.end());
        int res_id = res - size_of_scc.begin();
        cout << *res << '\n';
        for (int i = 1; i <= n; i++)
            if (scc[i] == res_id)
                cout << i << ' ';
        cout << '\n';
    }
    return 0;
}