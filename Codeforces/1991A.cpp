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
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i % 2 == 0)
                res = max(res, x);
        }
        cout << res << '\n';
    }
    return 0;
}
