#include <bits/stdc++.h>
using namespace std;

mt19937 mt(time(0));

inline int randint(int a, int b) {
    return mt() % (b - a + 1) + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    vector<pair<int,int>> queries(m);
    vector<vector<int>> openings(n), closings(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        queries[i] = {a, b};
        openings[a].push_back(i);
        closings[b].push_back(i);
    }
    vector<int> res(m, 0);
    int k = 30;
    while (k--) {
        vector<int> guess(m), q_num(m, 0), num(n, 0);
        for (int i = 0; i < m; i++) {
            auto [a, b] = queries[i];
            guess[i] = (p[randint(a, b)]);
        }

        for (int i = 0; i < n; i++) {
            for (auto j : openings[i])
                q_num[j] = num[guess[j]];
            num[p[i]]++;
            for (auto j : closings[i])
                q_num[j] = num[guess[j]] - q_num[j];
        }

        for (int i = 0; i < m; i++) {
            auto [a, b] = queries[i];
            if (2 * q_num[i] > b - a + 1)
                res[i] = guess[i];
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << '\n';
    return 0;
}