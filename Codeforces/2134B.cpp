#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;

        for (auto& x : a)
            cout << x + (x % (k + 1)) * k << ' ';
        cout << '\n';
    }
}
