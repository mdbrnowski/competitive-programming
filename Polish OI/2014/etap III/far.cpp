#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int prev, vector<vector<int>>& tree, vector<int>& c, vector<int>& k, vector<int>& t) {
    for (auto u : tree[v]) {
        if (u == prev) continue;
        dfs(u, v, tree, c, k, t);
        k[v] += k[u] + 2;
    }

    sort(tree[v].begin(), tree[v].end(), [&](int x, int y) {
        return t[x] - k[x] > t[y] - k[y];
    });

    t[v] = c[v];
    int X = 1, i = -1;
    for (auto u : tree[v]) {
        i++;
        if (u == prev) continue;
        t[v] = max(t[v], X + t[u]);

        if (i < (int) tree[v].size() - 1)
            X += k[tree[v][i]] + 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> k(n, 0), t(n, 0);
    dfs(0, 0, tree, c, k, t);

    int res = max(t[0], (n - 1) * 2 + c[0]);
    cout << res << '\n';
    return 0;
}