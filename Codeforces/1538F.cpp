#include <bits/stdc++.h>
using namespace std;

int result(int x) {
    int res = x, i = 10;
    while (i <= x)
        res += x/i, i *= 10;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << result(r) - result(l) << '\n';
    }
    return 0;
}