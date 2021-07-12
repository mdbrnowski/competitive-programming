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
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        cout << 0 << ' ';
        for (int i = 1; i < n; i++) {
            cout << (a[i-1] & ~a[i]) << ' ';
            a[i] ^= (a[i-1] & ~a[i]);
        }
        cout << '\n';
    }
    return 0;
}