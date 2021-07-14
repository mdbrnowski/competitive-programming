#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k), b(k);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        vector<ll> c(n, INT_MAX);
        for (int i = 0; i < k; i++)
            c[a[i] - 1] = b[i];

        vector<ll> L(n, INT_MAX), R(n, INT_MAX);
        ll p = INT_MAX;
        for (int i = 0; i < n; i++)
            L[i] = p = min(p + 1, c[i]);
        p = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
            R[i] = p = min(p + 1, c[i]);

        for (int i = 0; i < n; i++)
            cout << min(L[i], R[i]) << ' ';
        cout << '\n';
    }
    return 0;
}