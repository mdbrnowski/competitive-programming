#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> tree;
vector<int> link;
vector<int> order;

void dfs_align(int v, int u) {
    link[v] = u;
    auto& [L, R] = tree[v];
    auto& [uL, uR] = tree[u];
    if (R) {
        if (uR == 0) uR = R;
        else dfs_align(R, uR);
    }
    if (L) {
        if (uL == 0) uL = L;
        else {
            if (link[uL] == 1) dfs_align(L, 1);
            else dfs_align(L, uL);
        }
    }
}

void bfs(int start) {
    int timer = 1;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order[v] = timer++;
        auto [u_1, u_2] = tree[v];
        if (u_1) q.push(u_1);
        if (u_2) q.push(u_2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, z;
    cin >> n;
    tree.resize(n+1), order.resize(n+1), link.resize(n+1);
    iota(link.begin(), link.end(), 0);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        tree[i] = {l, r};
    }

    if (tree[1].first)
        dfs_align(tree[1].first, 1);
    if (tree[1].second)
        bfs(tree[1].second);

    cin >> z;
    for (int i = 0; i < z; i++) {
        int x, y;
        cin >> x >> y;
        cout << (order[link[x]] >= order[link[y]] ? "TAK" : "NIE") << '\n';
    }
    return 0;
}