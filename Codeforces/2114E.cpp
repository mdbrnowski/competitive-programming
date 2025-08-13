#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void dfs(int v, int prev, const vector<vi>& tree, const vll& a, vll& mini, vll& maxi) {
    for (auto u : tree[v]) {
        if (u == prev)
            continue;
        maxi[u] = max(a[u], a[u] - mini[v]);
        mini[u] = min(a[u], a[u] - maxi[v]);
        dfs(u, v, tree, a, mini, maxi);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll a(n);
        for (auto& x : a)
            cin >> x;
        vector<vi> tree(n);
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            tree[v].push_back(u);
            tree[u].push_back(v);
        }

        vll mini(n, 0), maxi(n, 0);

        mini[0] = maxi[0] = a[0];
        dfs(0, 0, tree, a, mini, maxi);

        for (auto r : maxi)
            cout << r << ' ';
        cout << '\n';
    }
}
