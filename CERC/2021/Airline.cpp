#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int v, int prev, vector<vector<int>>& tree, vector<int>& parent, vector<int>& depth,
        vector<unordered_map<int, ll>>& subtree_size) {
    int sts = 1;
    parent[v] = prev;
    depth[v] = depth[prev] + 1;
    for (auto u : tree[v]) {
        if (u == prev)
            continue;
        subtree_size[v][u] = dfs(u, v, tree, parent, depth, subtree_size);
        sts += subtree_size[v][u];
    }
    if (v != 0)
        subtree_size[v][prev] = tree.size() - sts;
    return sts;
}

vector<int> find_path(int a, int b, vector<int>& parent, vector<int>& depth) {
    vector<int> path_a, path_b;
    while (depth[a] > depth[b]) {
        path_a.push_back(a);
        a = parent[a];
    }
    while (depth[b] > depth[a]) {
        path_b.push_back(b);
        b = parent[b];
    }
    while (a != b) {
        path_a.push_back(a);
        path_b.push_back(b);
        a = parent[a];
        b = parent[b];
    }
    path_a.push_back(a);
    for (int i = path_b.size() - 1; i >= 0; i--)
        path_a.push_back(path_b[i]);
    return path_a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> parent(n), depth(n, -1);
    vector<unordered_map<int, ll>> subtree_size(n);
    dfs(0, 0, tree, parent, depth, subtree_size);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        vector<int> path = find_path(x, y, parent, depth);
        int ps = path.size();

        ll res = 0;
        res += (n - subtree_size[x][path[1]]) * (n - subtree_size[y][path[ps - 2]]);
        for (int i = 1, j; (j = i + ps / 2 + 1) < ps; i++) {
            ll own = n - subtree_size[path[i]][path[i - 1]] - subtree_size[path[i]][path[i + 1]];
            ll other = n - subtree_size[path[j]][path[j - 1]];
            res += own * other;
        }
        reverse(path.begin(), path.end());
        for (int i = 1; i + ps / 2 + 1 < ps; i++) {
            // we don't really need j at this point since we don't want to count on-path pairs twice
            int j = ps - 1;
            ll own = n - subtree_size[path[i]][path[i - 1]] - subtree_size[path[i]][path[i + 1]];
            ll other = n - subtree_size[path[j]][path[j - 1]];
            res += own * other;
        }
        cout << res << '\n';
    }
    return 0;
}
