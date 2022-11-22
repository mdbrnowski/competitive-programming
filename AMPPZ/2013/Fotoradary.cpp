#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

void process(int v, vector<unordered_set<int>>& tree, vi& leaves, vi& res) {
    res.push_back(v);
    for (auto u : tree[v]) {
        tree[u].erase(v);
        if (tree[u].size() == 1)
            leaves.push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<unordered_set<int>> tree(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    if (n == 1) { cout << "1\n1\n"; return 0; }
    vi res, leaves, leaves2;
    for (int i = 0; i < n; i++) {
        if (tree[i].size() == 1)
            leaves.push_back(i);
    }
    for (int L = 0; L < k/2; L++) {
        for (auto v : leaves)
            process(v, tree, leaves2, res);
        leaves.clear();
        swap(leaves, leaves2);
    }
    if (k % 2 && leaves.size())
        res.push_back(leaves[0]);

    cout << sz(res) << '\n';
    for (auto r : res)
        cout << r + 1 << ' ';
    cout << '\n';
    return 0;
}
