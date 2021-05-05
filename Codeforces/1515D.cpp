#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> L(n, 0), R(n, 0);
        for (int i = 0; i < n; i++) {
            int sock;
            cin >> sock;
            if (i < l) L[sock-1]++;
            else R[sock-1]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int mini = min(L[i], R[i]);
            L[i] -= mini, R[i] -= mini;
            l -= mini; r -= mini;
        }
        if (l < r) swap(l, r), swap(L, R);
        for (int i = 0; i < n; i++) {
            int e = min(L[i] - (L[i] & 1), l-r);
            res += e / 2;
            l -= e;
        }
        res += (l-r) / 2 + (l+r) / 2;
        cout << res << '\n';
    }
    return 0;
}