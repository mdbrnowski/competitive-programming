#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<unordered_map<char,int>> rows(n), cols(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            rows[i][c]++;
            cols[j][c]++;
        }
    }

    vector<tuple<char,int,char>> res;
    vector<bool> row_deleted(n), col_deleted(m);
    queue<pair<char,int>> q;
    for (int i = 0; i < n; i++)
        if (sz(rows[i]) == 1)
            q.push({'R', i});
    for (int i = 0; i < m; i++)
        if (sz(cols[i]) == 1)
            q.push({'K', i});

    while (q.size()) {
        auto [rk, i] = q.front(); q.pop();
        if (rk == 'R') {
            if (sz(rows[i]) == 0)
                continue;
            char c = rows[i].begin()->first;
            res.push_back({'R', i, c});
            for (int j = 0; j < m; j++) {
                if (!col_deleted[j] && --cols[j][c] == 0) {
                    cols[j].erase(c);
                    if (sz(cols[j]) == 1) {
                        q.push({'K', j});
                        col_deleted[j] = true;
                    }
                }
            }
        }
        if (rk == 'K') {
            if (sz(cols[i]) == 0)
                continue;
            char c = cols[i].begin()->first;
            res.push_back({'K', i, c});
            for (int j = 0; j < n; j++) {
                if (!row_deleted[j] && --rows[j][c] == 0) {
                    rows[j].erase(c);
                    if (sz(rows[j]) == 1) {
                        q.push({'R', j});
                        row_deleted[j] = true;
                    }
                }
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << sz(res) << '\n';
    for (auto [rk, i, color] : res)
        cout << rk << ' ' << i + 1 << ' ' << color << '\n';
    return 0;
}
