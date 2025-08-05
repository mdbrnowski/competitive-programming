#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
#define sz(x) (int)(x).size()

void dfs(int v, int prev, const vector<vi>& tree, vector<pi>& result, bool s) {
    for (auto u : tree[v]) {
        if (u == prev)
            continue;
        if (s)
            result.push_back({u, v});
        else
            result.push_back({v, u});
        dfs(u, v, tree, result, !s);
    }
}

bool solve(int n, const vector<vi>& tree, vector<pi>& result) {
    for (int v = 0; v < n; v++) {
        if (sz(tree[v]) == 2) {
            int a = tree[v][0], b = tree[v][1];
            result.push_back({a, v});
            result.push_back({v, b});
            dfs(a, v, tree, result, false);
            dfs(b, v, tree, result, true);
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vi> tree(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<pi> result;
        if (solve(n, tree, result)) {
            cout << "YES\n";
            for (auto [a, b] : result)
                cout << a + 1 << ' ' << b + 1 << '\n';
        } else {
            cout << "NO\n";
        }
    }
}
