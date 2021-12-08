#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> d;
vector<vector<int>> tree;
vector<bool> visited;
vector<ll> subtree_sum;
vector<ll> vertex_transfer;

ll dfs_sum(int v) {
    subtree_sum[v] = d[v];
    for (auto u : tree[v]) {
        if (visited[u]) continue;
        visited[u] = true;
        subtree_sum[v] += dfs_sum(u);
    }
    return subtree_sum[v];
}

void dfs_propagate(int v) {
    for (auto u : tree[v]) {
        if (visited[u]) continue;
        visited[u] = true;
        vertex_transfer[u] += vertex_transfer[v];
        dfs_propagate(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    d.resize(n), tree.resize(n);
    for (auto& x : d) cin >> x;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        d[i] -= y;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    if (accumulate(d.begin(), d.end(), 0LL) != 0) {
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";

    subtree_sum.assign(n, 0);
    visited.assign(n, false);
    dfs_sum(0);

    vertex_transfer.assign(n, 0);
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        vertex_transfer[i] = subtree_sum[i];
    dfs_propagate(0);

    ll mini = *min_element(vertex_transfer.begin(), vertex_transfer.end());
    vector<ll> res = {0, 0};
    for (auto x : vertex_transfer) {
        res[0] += x - mini;
        if (res[0] >= 1e18)
            res[0] -= 1e18, res[1]++;
    }
    if (res[1]) cout << res[1] << setw(18) << setfill('0');
    cout << res[0] << '\n';
    return 0;
}