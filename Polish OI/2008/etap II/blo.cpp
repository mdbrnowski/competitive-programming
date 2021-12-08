#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> graph;
vector<ll> res;
vector<bool> visited;
vector<int> d, low;
int n;
int timer = 0;

int dfs(int v, int p) {
    int to_visit = 1;
    int blocked = 0;
    visited[v] = true;
    d[v] = low[v] = timer++;
    for (int c : graph[v]) {
        if (c == p) continue;
        if (visited[c])
            low[v] = min(low[v], d[c]);
        else {
            int size = dfs(c, v);
            to_visit += size;
            low[v] = min(low[v], low[c]);
            if (low[c] >= d[v]) {
                res[v] += (ll) (n-1-size) * size;
                blocked += size;
            }
        }
    }
    res[v] += (ll) (n-1-blocked) * blocked;
    return to_visit;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    graph.resize(n+1);
    res.assign(n+1, 2*(n-1));
    visited.assign(n+1, false), d.assign(n+1, -1), low.assign(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << res[i] << '\n';
    return 0;
}