#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<pair<int,int>>> res(n, vector<pair<int,int>>(m));
        res[0][0] = {a[0][0], a[0][0]};
        for (int i = 1; i < n; i++)
            res[i][0].first = res[i-1][0].first + a[i][0],
            res[i][0].second = res[i-1][0].second + a[i][0];
        for (int j = 1; j < m; j++)
            res[0][j].first = res[0][j-1].first + a[0][j],
            res[0][j].second = res[0][j-1].second + a[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                res[i][j].first = min(res[i][j-1].first, res[i-1][j].first) + a[i][j],
                res[i][j].second = max(res[i][j-1].second, res[i-1][j].second) + a[i][j];
            }
        }
        int l = res[n-1][m-1].first;
        int r = res[n-1][m-1].second;
        cout << (l <= 0 && 0 <= r && r % 2 == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}