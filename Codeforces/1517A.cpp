#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n % 2050 != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll res = 0;
        n /= 2050;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        cout << res << '\n';
    }
    return 0;
}