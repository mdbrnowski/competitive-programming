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
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int x = sqrt(a);
            if (x * x != a) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}