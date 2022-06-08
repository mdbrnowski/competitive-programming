#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n), f(n), d(n);
        for (auto& x : s) cin >> x;
        for (auto& x : f) cin >> x;

        d[0] = f[0] - s[0];
        for (int i = 1; i < n; i++)
            d[i] = min(f[i] - s[i], f[i] - f[i-1]);
        for (auto x : d)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}