#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        sort(a.rbegin(), a.rend());

        ll alice_sum = 0, bob_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                alice_sum += a[i];
            else
                bob_sum += a[i];
        }

        for (int i = 0; i < n - 1; i += 2) {
            ll diff = min(k, a[i] - a[i + 1]);
            k -= diff;
            // a[i + 1] += diff;
            bob_sum += diff;
        }

        cout << alice_sum - bob_sum << '\n';
    }
    return 0;
}
