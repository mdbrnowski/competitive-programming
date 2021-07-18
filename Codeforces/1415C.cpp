#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, k, x, y; string s;
        cin >> n >> p >> k >> s >> x >> y;
        vector<int> c(n+1, 0);
        int res = INT_MAX;
        for (int i = n; i > 0; i--)
            c[i] = ((1 - (s[i-1] - '0')) + (i+k > n ? 0 : c[i+k]));
        for (int i = 0; i + p <= n; i++)
            res = min(res, i * y + c[i+p] * x);
        cout << res << '\n';
    }
    return 0;
}