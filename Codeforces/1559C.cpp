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
        vector<int> a(n), res(n);
        for (auto& x : a) cin >> x;
        int first_one = find(a.begin(), a.end(), 1) - a.begin();
        iota(res.begin(), res.end(), 0);
        res.insert(res.begin() + first_one, n);
        for (auto x : res) cout << x + 1 << ' ';
        cout << '\n';
    }
    return 0;
}