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
        for (auto& x : a) cin >> x;
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % n != 0) {
            cout << -1 << '\n';
            continue;
        }
        int res = 0;
        sum /= n;
        for (auto x : a) if (x > sum) res++;
        cout << res << '\n';
    }
    return 0;
}