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
        int m = 0;
        map<int,int> r;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            r[a]++;
            m = max(m, r[a]);
        }
        int res;
        if (m <= n - m) res = n & 1;
        else res = 2 * m - n;
        cout << res << '\n';
    }
    return 0;
}