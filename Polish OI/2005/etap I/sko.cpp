#include <bits/stdc++.h>
using namespace std;

pair<int,int> extended_gcd(int x, int y) {
    if (y == 0) return {1, 0};
    auto [a, b] = extended_gcd(y, x % y);
    return {b, a - (x / y) * b};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (auto& [x, y] : v) cin >> x >> y;
    auto& res = v[0];
    int res_beta = 0;
    for (int i = 1; i < n; i++) {
        auto [x_1, y_1] = res;
        auto [x_2, y_2] = v[i];
        auto [p, q] = extended_gcd(y_1, y_2);
        int y = __gcd(y_1, y_2);
        res = {p * x_1 + q * x_2, y};
        int beta = abs(x_1 * y_2 / y - x_2 * y_1 / y);
        res_beta = __gcd(res_beta, beta);
        if (res_beta)
            res.first %= res_beta;
    }
    cout << res.first << ' ' << res.second << '\n';
    cout << res_beta << ' ' << 0 << '\n';
    return 0;
}