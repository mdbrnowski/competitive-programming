#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n;
    vector<int> depth;
    vector<int> maxlen_1, maxlen_2, maxlen_up;
    vector<vector<int>> tree;
    vector<vector<int>> ancestor;
    Tree(int _n) : n(_n), depth(n, -1), maxlen_1(n, 0), maxlen_2(n, 0), maxlen_up(n, 0),
                   tree(n), ancestor(n, vector<int>(20)) {}
    void calc_depth(int v=0, int prev=0) {
        depth[v] = depth[prev] + 1;
        ancestor[v][0] = prev;
        for (auto u : tree[v])
            if (u != prev)
                calc_depth(u, v);
    }
    void calc_lenghts(int v=0, int prev=0) {
        vector<int> lenghts;
        for (auto u : tree[v]) {
            if (u != prev) {
                calc_lenghts(u, v);
                lenghts.push_back(maxlen_1[u] + 1);
            }
        }
        sort(lenghts.rbegin(), lenghts.rend());
        if (lenghts.size() > 0)
            maxlen_1[v] = lenghts[0];
        if (lenghts.size() > 1)
            maxlen_2[v] = lenghts[1];
    }
    void calc_lengths_up(int v=0, int prev=0) {
        for (auto u : tree[v]) {
            if (u != prev) {
                if (maxlen_1[v] == maxlen_1[u] + 1)
                    maxlen_up[u] = max(maxlen_2[v] + 1, maxlen_up[v] + 1);
                else
                    maxlen_up[u] = max(maxlen_1[v] + 1, maxlen_up[v] + 1);
                calc_lengths_up(u, v);
            }
        }
    }
    void calc_ancestors() {
        for (int k = 1; k < 20; k++)
            for (int i = 0; i < n; i++)
                ancestor[i][k] = ancestor[ancestor[i][k-1]][k-1];
    }
    int chase(int k, int m) {
        if (k == m) return 0;
        int up;
        int mz;  // the last vertex the mouse can reach
        int kz;  // the last vertex the cat can reach
        if (depth[m] >= depth[k]) {
            mz = m;
            kz = ancestor[m][0];
            up = (dist(k, m) - 1) / 2;
        }
        if (depth[m] < depth[k]) {
            mz = ancestor[k][0];
            kz = k;
            up = dist(k, m) / 2;
        }

        for (int j = 20; j >= 0; j--) {
            if ((1 << j) <= up) {
                mz = ancestor[mz][j];
                kz = ancestor[kz][j];
                up -= (1 << j);
            }
        }

        int res = dist(k, mz);

        if (depth[mz] >= depth[kz])
            res += maxlen_1[mz];
        else {
            if (maxlen_1[kz] + 1 == maxlen_1[mz])
                res += max(maxlen_2[mz], maxlen_up[mz]);
            else
                res += max(maxlen_1[mz], maxlen_up[mz]);
        }
        return res;
    }

    private:
    int lca(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);
        for (int k = 19; k >= 0; k--) {
            if (depth[ancestor[b][k]] >= depth[a])
                b = ancestor[b][k];
        }
        if (a == b) return a;
        for (int k = 19; k >= 0; k--) {
            if (ancestor[a][k] != ancestor[b][k])
                a = ancestor[a][k],
                b = ancestor[b][k];
        }
        return ancestor[a][0];
    }
    int dist(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto T = Tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        T.tree[a].push_back(b);
        T.tree[b].push_back(a);
    }
    T.calc_depth();
    T.calc_lenghts();
    T.calc_lengths_up();
    T.calc_ancestors();
    int q;
    cin >> q;
    while (q--) {
        int k, m;
        cin >> k >> m;
        k--, m--;
        cout << T.chase(k, m) << '\n';
    }
    return 0;
}