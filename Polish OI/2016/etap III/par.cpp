#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> dp;    // dp[v] = best result for a path that goes downwads from v to a leaf
vector<bool> pll;  // is a leaf or a parent only of leaves

void dfs_pll(int v, int prev) {
    for (auto u : tree[v]) {
        if (u == prev) continue;
        if (tree[u].size() > 1)
            pll[v] = false;
        dfs_pll(u, v);
    }
}

void dfs(int v, int prev, int& res) {
    for (auto u : tree[v]) {
        if (u == prev) continue;
        dfs(u, v, res);
        res = max(res, dp[v] + !pll[v] + dp[u] + !pll[u] - 1 + (v != 0));  // path goes only through v and its descendants
        dp[v] = max(dp[v], dp[u] + (int) tree[v].size() - 1 - (v != 0));
    }
    res = max(res, dp[v] + (v != 0) + !pll[v]);  // path starts in v and goes downwards
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    if (n == 2) { cout << 0 << '\n'; return 0; }

    pll.resize(n, true);
    dfs_pll(0, 0);

    int res = 0;
    dp.resize(n, 0);
    dfs(0, 0, res);

    cout << res << '\n';
    return 0;
}