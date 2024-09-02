#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

vector<char> bfs(vector<string>& a, int n, int m) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<char>> parent(n, vector<char>(m, '?'));
    while (sz(q)) {
        auto [i, j] = q.front();
        q.pop();
        if (i + 1 < n && a[i + 1][j] != '#' && parent[i + 1][j] == '?') {
            parent[i + 1][j] = 'D';
            q.push({i + 1, j});
        }
        if (j + 1 < m && a[i][j + 1] != '#' && parent[i][j + 1] == '?') {
            parent[i][j + 1] = 'P';
            q.push({i, j + 1});
        }
    }
    vector<char> path = {};
    int i = n - 1, j = m - 1;
    while (i != 0 || j != 0) {
        if (parent[i][j] == '?')
            break;
        path.push_back(parent[i][j]);
        if (parent[i][j] == 'D')
            i--;
        else
            j--;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& row : a)
            cin >> row;
        auto path = bfs(a, n, m);
        if (sz(path) != n + m - 2) {
            cout << "NIE\n";
            continue;
        }
        cout << "TAK\n";

        int i = 0, j = 0;
        vector<bool> ch_row(n, false), ch_col(m, false);
        if (a[0][0] == '@')
            ch_row[0] = true;
        for (auto c : path) {
            if (c == 'D')
                i++;
            else
                j++;

            if (a[i][j] == '@' && !ch_row[i] && !ch_col[j]) {
                if (c == 'D')
                    ch_row[i] = true;
                else
                    ch_col[j] = true;
            }
            if (a[i][j] == 'O') {
                if (ch_row[i] && !ch_col[j])
                    ch_col[j] = true;
                if (ch_col[j] && !ch_row[i])
                    ch_row[i] = true;
            }
        }

        for (auto b : ch_row)
            cout << (b ? 'T' : 'N');
        cout << '\n';

        for (auto b : ch_col)
            cout << (b ? 'T' : 'N');
        cout << '\n';

        for (auto c : path)
            cout << c;
        cout << '\n';
    }
    return 0;
}
