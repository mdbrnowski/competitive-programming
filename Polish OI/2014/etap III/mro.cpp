#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll G_MAX = 1e9+7;

void dfs(int v, int prev, vector<vector<int>>& tree, map<int,int>& intervals, int m_min_prev, int m_max_prev) {
    int p = tree[v].size() - 1;
    if (p == 0) {
        intervals[m_min_prev]++;
        intervals[m_max_prev + 1]--;
    } else {
        int m_min = min((ll) m_min_prev * p, G_MAX);
        int m_max = min((ll) m_max_prev * p + p - 1, G_MAX);
        for (auto u : tree[v]) {
            if (u != prev)
                dfs(u, v, tree, intervals, m_min, m_max);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, g, k;
    cin >> n >> g >> k;
    vector<int> m(g);
    for (auto& x : m) cin >> x;
    sort(m.begin(), m.end());
    vector<vector<int>> tree(n);
    int start_a, start_b;
    cin >> start_a >> start_b;
    start_a--, start_b--;
    tree[start_a].push_back(start_b);
    tree[start_b].push_back(start_a);
    for (int i = 1; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    map<int,int> intervals;
    intervals[G_MAX] = 0;
    dfs(start_a, start_b, tree, intervals, k, k);
    dfs(start_b, start_a, tree, intervals, k, k);

    ll res = 0;
    int current = 0;
    auto it = intervals.begin();
    for (auto group : m) {
        while (it->first <= group) {
            current += it->second;
            it++;
        }
        res += current;
    }

    cout << res * k << '\n';
    return 0;
}