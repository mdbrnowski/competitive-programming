#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    for (int i = 1; i < n; i++) {
        int diff = max(0, a[i] + a[i-1] - k);
        res += diff;
        a[i] -= min(a[i], diff);
        a[i-1] -= diff - min(a[i], diff);
    }
    cout << res << '\n';
    return 0;
}