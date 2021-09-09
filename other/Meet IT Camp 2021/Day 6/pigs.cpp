#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;
    int a_1, a_2;
    cin >> a_1;
    if (n == 1) return a_1 == k;
    cin >> a_2;
    if (n == 2) return a_1 - a_2 == k;
    vector<int> a(n-2);
    for (auto& x : a) cin >> x;
    k = abs(k - a_1 + a_2);
    int goal  = (accumulate(a.begin(), a.end(), 0) - k) / 2;
    if (goal < 0 || accumulate(a.begin(), a.end(), 0) % 2 != k % 2) return false;
    bitset<1000003> dp;
    dp[0] = 1;
    for (auto x : a) {
        dp |= (dp << x);
        if (dp[goal]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}