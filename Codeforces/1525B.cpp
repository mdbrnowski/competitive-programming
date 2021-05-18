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
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        int res;
        if (is_sorted(v.begin(), v.end())) res = 0;
        else if (v.front() == 1 || v.back() == n) res = 1;
        else if (v.front() == n && v.back() == 1) res = 3;
        else res = 2;
        cout << res << '\n';
    }
    return 0;
}