#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<bool> b(n - 1, false);
        for (auto& x : a) cin >> x;
        for (int i = 0; i < n - 1; i++)
            if (a[i] < a[i + 1] * 2) b[i] = true;
        int res = 0, curr = 0;
        for (auto ok : b) {
            if (ok) curr++;
            else curr = 0;
            if (curr >= k) res++;
        }
        cout << res << '\n';
    }
    return 0;
}