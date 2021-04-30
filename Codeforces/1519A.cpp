#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll r, b, d;
        cin >> r >> b >> d;
        if (r < b) swap(r, b);
        cout << (b * (d + 1) >= r ? "YES" : "NO") << '\n';
    }
    return 0;
}