#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i+i; j <= n; j += i)
            dp[j]++;

    int sum = dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (sum + dp[i]) % MOD;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}