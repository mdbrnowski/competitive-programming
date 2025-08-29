#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto& row : a)
        for (auto& c : row)
            cin >> c;

    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            set<char> s;
            s.insert(a[i][j]);
            s.insert(a[i + 1][j]);
            s.insert(a[i][j + 1]);
            s.insert(a[i + 1][j + 1]);

            if (s == set<char>({'f', 'a', 'c', 'e'}))
                res++;
        }
    }
    cout << res << '\n';
}
