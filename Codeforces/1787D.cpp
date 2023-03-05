#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void dfs(int v, vector<vi>& graph, vi& cc, vector<bool>& ok, int cc_n) {
    cc[v] = cc_n;
    for (auto u : graph[v]) {
        if (u == 0) {
            ok[cc_n] = true;
            continue;
        }
        if (cc[u] == 0)
            dfs(u, graph, cc, ok, cc_n);
    }
}

void dfs2(int v, int prev, vector<vi>& graph, vi& subtree_size) {
    subtree_size[v] = 1;
    for (auto u : graph[v]) {
        if (u == 0 || u == prev) continue;
        dfs2(u, v, graph, subtree_size);
        subtree_size[v] += subtree_size[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n+1);
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            x += i;
            a[i] = (x >= 1 && x <= n) ? x : 0;
        }
        vector<vi> ugraph(n+1);  // underlying graph
        for (int i = 1; i <= n; i++)
            ugraph[i].push_back(a[i]),
            ugraph[a[i]].push_back(i);

        ll res = 0;
        vector<bool> on_main_path(n+1, false);
        int main_path = 0;
        int p = 1;
        while (p != 0 && !on_main_path[p]) {
            on_main_path[p] = true;
            main_path++;
            p = a[p];
        }
        if (p == 0)
            res += (ll) (n - main_path) * (2 * n + 1);

        vi cc(n+1, 0);  // (weakly) connected component
        vector<bool> ok(n+1, false);  // ok[cc_n] = true if every path ends up in 0
        int cc_n = 1;
        for (int i = 1; i <= n; i++) {
            if (cc[i] == 0)
                dfs(i, ugraph, cc, ok, cc_n);
            cc_n++;
        }

        int in_main_cc_or_not_ok = 0;
        for (int i = 1; i <= n; i++) {
            if (cc[i] == 1 || !ok[cc[i]])
                in_main_cc_or_not_ok++;
        }
        res += (ll) main_path * (2 * n + 1 - in_main_cc_or_not_ok);

        if (p == 0) {  // from main path to main cc
            vi subtree_size(n+1, 0);
            dfs2(1, 0, ugraph, subtree_size);
            for (int i = 1; i <= n; i++)
                if (on_main_path[i])
                    res += subtree_size[a[i]];
        }

        cout << res << '\n';
    }
    return 0;
}