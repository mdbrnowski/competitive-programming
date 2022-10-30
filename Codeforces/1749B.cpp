#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        ll res = accumulate(a.begin(), a.end(), 0LL);
        res += accumulate(b.begin(), b.end(), 0LL) - *max_element(b.begin(), b.end());
        cout << res << '\n';
    }
    return 0;
}