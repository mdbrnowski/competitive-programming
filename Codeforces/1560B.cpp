#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int n = 2 * abs(a - b);
        if (max({a, b, c}) > n) cout << -1;
        else if (c > n/2) cout << c - n/2;
        else cout << c + n/2;
        cout << '\n';
    }
    return 0;
}