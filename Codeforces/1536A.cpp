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
        bool res = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < 0) res = false;
        }
        cout << (res ? "YES" : "NO") << '\n';
        if (res) {
            cout << 101 << '\n';
            for (int i = 0; i <= 100; i++) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}