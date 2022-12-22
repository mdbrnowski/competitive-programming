#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

inline bool not_in(int a, vi& vec) {
    return (sz(vec) < 1 || (vec[0] != a && (
            sz(vec) < 2 || (vec[1] != a && (
            sz(vec) < 3 || (vec[2] != a && (
            sz(vec) < 4 || (vec[3] != a)))))))
            );
}

void dfs(int v, vector<vi>& graph, vi& dp, vi& deleted) {
    dp[v] = 1;
    for (auto u : graph[v])
        if (not_in(u, deleted)) {
            if (dp[u] == 0)
                dfs(u, graph, dp, deleted);
            dp[v] = max(dp[v], 1 + dp[u]);
        }
}

void calc_longest_paths(int n, vector<vi>& graph, vi& dp, vi& deleted) {
    for (int v = 0; v < n; v++)
        if (dp[v] == 0 && not_in(v, deleted))
            dfs(v, graph, dp, deleted);
}

int check(int k, int n, vector<vi>& graph, vi& deleted) {
    if (k == 0) {
        vi dp(n, 0);
        calc_longest_paths(n, graph, dp, deleted);
        return *max_element(dp.begin(), dp.end());
    }

    vi dp(n, 0);  // length of the longest path from a given vertex
    calc_longest_paths(n, graph, dp, deleted);
    int s = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> longest_path = {s};

    for (int len = dp[s] - 1; len >= 1; len--) {
        int i = 0;
        s = longest_path.back();
        while (dp[graph[s][i]] < len) i++;
        longest_path.push_back(graph[s][i]);
    }

    int mini = 1e9;
    for (auto v : longest_path) {
        deleted.push_back(v);
        mini = min(mini, check(k-1, n, graph, deleted));
        deleted.pop_back();
    }
    return mini;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> graph(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
    }
    vi deleted;
    if (k >= n)
        cout << 0 << '\n';
    else
        cout << check(k, n, graph, deleted) << '\n';
    return 0;
}