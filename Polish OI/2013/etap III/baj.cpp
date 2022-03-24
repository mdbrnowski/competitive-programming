#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

struct SpecialArray {
    array<int, 3> t;
    SpecialArray(int val) : t({val, val, val}) {}
    int& operator[](int i) {
        return t[i + 1];
    }
    int min() {
        return *min_element(t.begin(), t.end());
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<SpecialArray> dp(n, SpecialArray(INF));
    dp[0][a[0]] = 0;

    for (int i = 1; i < n; i++) {
        for (int y = -1; y <= 1; y++) {
            if (dp[i - 1][y] >= INF) continue;
            int x = a[i], add = 0;
            do {
                if (x >= y)
                    dp[i][x] = min(dp[i][x], dp[i-1][y] + add);
                add++, x += y;
            } while (y != 0 && x >= -1 && x <= 1);
        }
    }

    int res = dp.back().min();
    if (res < INF) cout << res << '\n';
    else cout << "BRAK\n";
    return 0;
}