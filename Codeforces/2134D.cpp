#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

vi find_diameter(int n, const vector<vi>& tree) {
    vi dist(n, -1), prev(n, -1);

    function<void(int)> dfs = [&](int v) {
        for (auto u : tree[v]) {
            if (u == prev[v])
                continue;
            dist[u] = dist[v] + 1;
            prev[u] = v;
            dfs(u);
        }
    };

    dist[0] = 0;
    dfs(0);
    int x = max_element(dist.begin(), dist.end()) - dist.begin();

    dist.assign(n, -1), prev.assign(n, -1);
    dist[x] = 0;
    dfs(x);
    int y = max_element(dist.begin(), dist.end()) - dist.begin();

    vi diameter;
    while (y != x) {
        diameter.push_back(y);
        y = prev[y];
    }
    diameter.push_back(x);

    return diameter;
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
            int u, v;
            cin >> u >> v;
            u--, v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        bool path = true;
        vi diameter = find_diameter(n, tree);
        for (int i = 1; i < n - 1; i++) {
            if (sz(tree[diameter[i]]) > 2) {
                cout << diameter[i - 1] + 1 << ' ' << diameter[i] + 1 << ' ';
                for (auto c : tree[diameter[i]]) {
                    if (c != diameter[i - 1] && c != diameter[i + 1]) {
                        cout << c + 1 << '\n';
                        break;
                    }
                }
                path = false;
                break;
            }
        }
        if (path) {
            cout << "-1\n";
        }
    }
}
