#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
constexpr int INF = 1e9;

vector<vector<int>> bfs(vector<pii> starts, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pii> q;
    for (auto [i, j] : starts) {
        dist[i][j] = 0;
        q.push({i, j});
    }
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [di, dj] : vector<pii>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            if (0 <= i + di && i + di < n &&
                0 <= j + dj && j + dj < m &&
                dist[i + di][j + dj] == INF) {
                dist[i + di][j + dj] = dist[i][j] + 1;
                q.push({i + di, j + dj});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> a(n);
        for (auto& row : a)
            cin >> row;

        vector<pii> dots;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '.')
                    dots.push_back({i, j});

        auto dist_from_dot = bfs(dots, n, m);
        vector<pii> lairs;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dist_from_dot[i][j] > k)
                    lairs.push_back({i, j});

        auto dist_from_lairs = bfs(lairs, n, m);
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ok &= ((dist_from_lairs[i][j] <= k) == (a[i][j] == 'x'));

        cout << (ok ? "TAK" : "NIE") << '\n';
    }
    return 0;
}
