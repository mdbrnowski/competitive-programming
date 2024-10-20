#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> peaks;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            ll x = 0;
            for (int k = i; k <= j; k++)
                x = x * 10 + k;
            for (int k = j - 1; k >= i; k--)
                x = x * 10 + k;
            peaks.push_back(x);
        }
    }
    sort(peaks.begin(), peaks.end());

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, m;
        cin >> a >> b >> m;
        int res = 0;
        auto l = lower_bound(peaks.begin(), peaks.end(), a);
        auto r = upper_bound(peaks.begin(), peaks.end(), b);
        while (l != r) {
            if (*l % m == 0)
                res++;
            l++;
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
