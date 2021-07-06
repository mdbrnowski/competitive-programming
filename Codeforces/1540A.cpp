#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n+1);
        for (int i = 1; i <= n; i++) cin >> d[i];
        sort(d.begin(), d.end());
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += (ll) d[i] * (n - 2*i + 1);
        cout << res + d[n] << '\n';
    }
    return 0;
}