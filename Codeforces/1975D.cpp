#include <bits/stdc++.h>
using namespace std;

int dfs(int v, int prev, vector<vector<int>>& tree) {
    int depth = 0;
    for (auto u : tree[v]) {
        if (u == prev)
            continue;
        depth = max(dfs(u, v, tree) + 1, depth);
    }
    return depth;
}

vector<int> find_path(int a, int b, vector<vector<int>>& tree) {
    queue<int> q;
    vector<int> parent(tree.size(), -1);
    parent[a] = a;
    q.push(a);
    while (parent[b] == -1) {
        int v = q.front();
        q.pop();
        for (auto u : tree[v]) {
            if (parent[u] == -1) {
                parent[u] = v;
                q.push(u);
            }
        }
    }
    vector<int> path;
    int x = b;
    while (x != parent[x]) {
        path.push_back(x);
        x = parent[x];
    }
    path.push_back(a);
    return path;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        vector<int> path = find_path(a, b, tree);  // b -> a
        int v = path[path.size() / 2];
        int depth = dfs(v, v, tree);
        cout << 2 * (n - 1) - depth + path.size() / 2 << '\n';
    }
    return 0;
}
