#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
#define sz(x) (int)(x).size()

pi find_ij(int n, int m, const vector<vi>& a) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                return {i, j};
}

bool is_eulerian(map<int, vector<int>>& graph) {
    int r = 0;
    map<int, bool> visited;
    for (auto [v, us] : graph) {
        visited[v] = false;
        if (sz(us) % 2 == 1)
            r++;
    }
    if (r != 0 && r != 2)
        return false;

    function<void(int)> dfs = [&](int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (auto u : graph[v])
            dfs(u);
    };
    dfs(graph.begin()->first);

    for (auto [v, ok] : visited) {
        if (!ok) return false;
    }
    return true;
}

bool solve(int n, int m, int start_i, int start_j, int k, const vector<vi>& a) {
    while (start_i - k >= 0)
        start_i -= k;
    while (start_j - k >= 0)
        start_j -= k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (a[i][j] && (i - start_i) % k != 0 && (j - start_j) % k != 0)
                return false;
    }

    map<int, vector<int>> graph;

    for (int i = start_i; i < n; i += k) {
        for (int j = start_j; j < m; j += k) {
            if (a[i][j] && !(i > 0 && a[i - 1][j]) && !(i < n - 1 && a[i + 1][j]) && !(j > 0 && a[i][j - 1]) && !(j < m - 1 && a[i][j + 1]))
                return false;

            int k_right = 0;
            for (int jj = j + 1; jj < m && jj < j + k; jj++) {
                if (a[i][jj])
                    k_right++;
            }
            if (a[i][j] && j + k < m && a[i][j + k] && k_right == k - 1) {
                graph[i * m + j].push_back(i * m + (j + k));
            } else if (k_right != 0)
                return false;

            int k_left = 0;
            for (int jj = j - 1; jj >= 0 && jj > j - k; jj--) {
                if (a[i][jj])
                    k_left++;
            }
            if (a[i][j] && j - k >= 0 && a[i][j - k] && k_left == k - 1) {
                graph[i * m + j].push_back(i * m + (j - k));
            } else if (k_left != 0)
                return false;

            int k_up = 0;
            for (int ii = i - 1; ii >= 0 && ii > i - k; ii--) {
                if (a[ii][j])
                    k_up++;
            }
            if (a[i][j] && i - k >= 0 && a[i - k][j] && k_up == k - 1) {
                graph[i * m + j].push_back((i - k) * m + j);
            } else if (k_up != 0)
                return false;

            int k_down = 0;
            for (int ii = i + 1; ii < n && ii < i + k; ii++) {
                if (a[ii][j])
                    k_down++;
            }
            if (a[i][j] && i + k < n && a[i + k][j] && k_down == k - 1) {
                graph[i * m + j].push_back((i + k) * m + j);
            } else if (k_down != 0)
                return false;
        }
    }

    return is_eulerian(graph);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto& row : a)
        for (auto& x : row)
            cin >> x;

    auto [i, j] = find_ij(n, m, a);
    int K = 0;
    if (i < n - 1 && a[i + 1][j]) {
        int ii = i + 1;
        while (ii < n && a[ii][j])
            K++, ii++;
    } else if (j < m - 1 && a[i][j + 1]) {
        int jj = j + 1;
        while (jj < m && a[i][jj])
            K++, jj++;
    } else {
        cout << "-1\n";
        return 0;
    }

    bool any = false;
    for (int k = 2; k <= K; k++) {
        if (K % k == 0 && solve(n, m, i, j, k, a)) {
            cout << k << ' ';
            any = true;
        }
    }
    cout << (any ? "\n" : "-1\n");
}
