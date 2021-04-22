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
        int xr = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            xr ^= a[i];
        }
        if (xr == 0) cout << "YES\n";
        else {
            int part_xor = 0, parts = 0;
            for (int i = 0; i < n; i++) {
                part_xor ^= a[i];
                if (part_xor == xr) {
                    parts++;
                    part_xor = 0;
                }
            }
            if (parts > 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}