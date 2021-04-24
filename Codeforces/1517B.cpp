#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<list<int>> v(n);
        REP(i, n) {
            REP(j, m) {
                int b;
                cin >> b;
                v[i].push_back(b);
            }
            v[i].sort();
        }
        vector<vector<int>> res(n, vector<int>(m));
        REP(j, m) {
            pair<int,int> mini = {0, INT_MAX};
            REP(i, n)
                if (v[i].front() < mini.second) mini = {i, v[i].front()};
            REP(i, n) {
                if (i == mini.first) {
                    res[i][j] = mini.second;
                    v[i].pop_front();
                } else {
                    res[i][j] = v[i].back();
                    v[i].pop_back();
                }
            }
        }
        REP(i, n) {
            REP(j, m) cout << res[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}