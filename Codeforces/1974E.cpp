#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m; ll x;
        cin >> m >> x;
        vector<int> c(m), h(m);
        for (int i = 0; i < m; i++)
            cin >> c[i] >> h[i];
        // dp[h] = cost -> lowest cost to buy happiness h
        map<int, ll> dp;
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            auto temp_dp = dp;
            for (auto [hap, cost] : dp) {
                ll new_cost = cost + c[i];
                int new_h = hap + h[i];
                if (new_cost <= i * x && (!temp_dp.count(new_h) || new_cost < temp_dp[new_h]))
                    temp_dp[new_h] = new_cost;
            }
            swap(dp, temp_dp);
        }
        cout << dp.rbegin()->first << '\n';
    }
    return 0;
}
