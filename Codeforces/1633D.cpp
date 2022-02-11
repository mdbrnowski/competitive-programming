#include <bits/stdc++.h>
using namespace std;

void calc_moves(vector<int>& moves) {
    moves[1] = 0;
    for (int a = 1; a < 1003; a++) {
        int x = a;
        while (x > 0) {
            int b = a + a / x;
            if (b >= 1003) break;
            moves[b] = min(moves[b], moves[a] + 1);
            x--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> moves(1003, 1e9);
    calc_moves(moves);
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (auto& x : b) cin >> x;
        for (auto& x : c) cin >> x;

        int sum = 0;
        for (auto& x : b) x = moves[x], sum += x;
        k = min(k, sum);
        vector<int> dp(k + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = k - b[i]; j >= 0; j--) {
                dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}