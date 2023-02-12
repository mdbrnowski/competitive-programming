#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string,int> names;
    int cur_name = 0;
    vi graph(n);
    vector<set<int>> rgraph(n);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (names.find(a) == names.end()) names[a] = cur_name++;
        if (names.find(b) == names.end()) names[b] = cur_name++;
        graph[names[a]] = names[b];
        rgraph[names[b]].insert(names[a]);
    }
    if (n & 1) { cout << -1 << '\n'; return 0; }

    int res = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (rgraph[i].size() == 0)
            q.push(i);
    set<int> in_cycles;
    for (int i = 0; i < n; i++)
        in_cycles.insert(i);

    while (q.size()) {
        res++;
        int u = q.front(); q.pop();
        int v = graph[u];
        in_cycles.erase(u);
        if (v == -1 || (graph[v] != -1 && graph[v] != v && graph[graph[v]] == v))
            continue;
        in_cycles.erase(v);

        for (auto x : rgraph[v])
            graph[x] = -1;
        int w = graph[v];
        if (w != -1) {
            rgraph[w].erase(v);
            if (rgraph[w].size() == 0)
                q.push(w);
        }
    }

    vector<bool> visited(n, false);
    for (auto u : in_cycles) {
        if (visited[u]) continue;
        int v = u, len = 0;
        while (!visited[v]) {
            visited[v] = true;
            v = graph[v];
            len++;
        }
        if (len != 2)
            res += (len + 1) / 2;
    }

    cout << res << '\n';
    return 0;
}