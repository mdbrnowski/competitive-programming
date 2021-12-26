#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void calc_segments(int n, vector<pair<int,int>>& w) {
    w.back().second = 1;
    for (int i = n-3; i >= 0; i--) {
        if ((w[i].first ^ w[i+1].first) >= 0)   // same sign
            w[i].second = w[i+1].second + 1;
        else
            w[i].second = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> v(n-1), w(n-1);
    for (auto& [l, r] : v) cin >> l >> r;
    for (int i = 0; i < n-1; i++)
        w[i].first = v[i].first - v[i].second;
    calc_segments(n, w);

    if (w[0].first > 0 && n - s < w[0].second) {
        auto m = min_element(w.begin(), w.begin() + n - s + 1);
        m->first = -1e9;
        calc_segments(n, w);
    }
    if (w[0].first < 0 && s - 1 < w[0].second) {
        auto m = max_element(w.begin(), w.begin() + s);
        m->first = 1e9;
        calc_segments(n, w);
    }

    vector<int> res = {s};
    deque<int> active;
    for (int i = 1; i <= n; i++)
        if (i != s) active.push_back(i);

    int idx = 0;
    while (!active.empty()) {
        auto [direc, num] = w[idx];
        if (direc >= 0) {
            vector<int> partial_res(active.end() - num, active.end());
            active.erase(active.end() - num, active.end());
            res.insert(res.end(), partial_res.begin(), partial_res.end());
        }
        if (direc < 0) {
            vector<int> partial_res(active.begin(), active.begin() + num);
            active.erase(active.begin(), active.begin() + num);
            res.insert(res.end(), partial_res.rbegin(), partial_res.rend());
        }
        idx += num;
    }

    ll res_cost = 0;
    for (int i = 0; i < n-1; i++) {
        if (res[i] > res[i+1])
            res_cost += v[i].first;
        else
            res_cost += v[i].second;
    }
    cout << res_cost << '\n';
    for (auto x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}