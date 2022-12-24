#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int v, int parent, int b, int xor_sum, vector<vector<pii>>& tree, set<int>& s) {
    for (auto [u, w] : tree[v])
        if (u != parent && u != b) {
            s.insert(xor_sum ^ w);
            dfs(u, v, b, xor_sum ^ w, tree, s);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<pii>> tree(n+1);
        for (int i = 0; i < n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        set<int> s1, s2;
        s1.insert(0);
        vi res;
        dfs(a, -1, b, 0, tree, s1);
        dfs(b, -1, b, 0, tree, s2);
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(res));
        cout << (res.size() ? "YES" : "NO") << '\n';
    }
    return 0;
}
