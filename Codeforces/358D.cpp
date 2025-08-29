#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct X {
    int no, l, r, both;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    for (auto& x : c)
        cin >> x;

    vector<X> dp(n);
    dp[0] = X{a[0], a[0], b[0], b[0]};
    for (int i = 1; i < n; i++) {
        dp[i].no = max(dp[i - 1].r, dp[i - 1].both) + a[i];
        dp[i].l = max(dp[i - 1].no, dp[i - 1].l) + b[i];
        dp[i].r = max(dp[i - 1].r, dp[i - 1].both) + b[i];
        dp[i].both = max(dp[i - 1].no, dp[i - 1].l) + c[i];
    }
    cout << max(dp.back().no, dp.back().l) << '\n';
}
