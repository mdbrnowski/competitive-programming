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
        vector<int> a(2*n), res(2*n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ' << a[i+n] << ' ';
        cout << '\n';
    }
    return 0;
}