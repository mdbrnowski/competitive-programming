#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    while (k--) {
        ll n, x, t;
        cin >> n >> x >> t;
        t /= x;
        if (t > n) cout << n*(n-1)/2 << '\n';
        else cout << t*(n-t) + t*(t-1)/2 << '\n';
    }
    return 0;
}