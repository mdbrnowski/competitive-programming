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
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        ll res = 0;
        for (int i = 0; i < n-1; i++)
            res = max(res, (ll) a[i] * a[i+1]);
        cout << res << '\n';
    }
    return 0;
}