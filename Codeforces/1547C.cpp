#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        bool possible = true;
        vector<int> res;
        for (int i = 0, j = 0; i+j < n+m; ) {
            if (i < n && a[i] <= k) {
                res.push_back(a[i]);
                if (a[i] == 0) k++;
                i++;
            }
            else if (j < m && b[j] <= k) {
                res.push_back(b[j]);
                if (b[j] == 0) k++;
                j++;
            }
            else {
                possible = false;
                break;
            }
        }
        if (possible) for (auto x : res) cout << x << ' ';
        else cout << -1;
        cout << '\n';
    }
    return 0;
}