#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int LIS(vector<ll>& vec) {
    int n = vec.size();
    int res = 0;
    vector<ll> dp(n + 1, 1e18);
    dp[0] = -1e18;
    for (auto x : vec) {
        int d = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        dp[d] = min(dp[d], x);
        res = max(res, d);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;

    partial_sum(a.begin(), a.end(), a.begin());

    if (a.back() < 0)
        cout << "-1\n";
    else {
        ll sum = a[n - 1];
        a.erase(remove_if(a.begin(), a.end(), [sum](ll x) {
                    return x < 0 || x > sum;
                }),
                a.end());
        cout << n - LIS(a) << '\n';
    }
    return 0;
}
