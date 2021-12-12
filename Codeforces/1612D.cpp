#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(ll a, ll b, ll x) {
    if (a == x || b == x) return true;
    if (x > max(a, b) || min(a, b) == 0) return false;
    if (a < b) swap(a, b);
    ll c = max(1LL, (a - max(b, x)) / b);
    return f(a - b * c, b, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;
        cout << (f(a, b, x) ? "YES" : "NO") << '\n';
    }
    return 0;
}