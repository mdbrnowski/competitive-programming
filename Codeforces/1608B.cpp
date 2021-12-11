#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (abs(a - b) > 1 || a + b > n - 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);

        if (a == b)
            for (int i = 0; i < 2*a; i += 2)
                swap(v[i+1], v[i+2]);
        if (a < b)
            for (int i = 0; i <= 2*a; i += 2)
                swap(v[i], v[i+1]);
        if (a > b)
            for (int i = n - 2*a; i < n-1; i += 2)
                swap(v[i], v[i+1]);

        for (auto x : v) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}