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
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        ll res = 0;
        for (auto& x : a)
            res += x / k,
            x %= k;
        sort(a.begin(), a.end());
        int i = 0, j = a.size() - 1;
        while (i < j) {
            if (a[i] + a[j] >= k)
                res++,
                j--;
            i++;
        }
        cout << res << '\n';
    }
    return 0;
}