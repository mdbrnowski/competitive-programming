#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vi a(n);
        for (auto& x : a) cin >> x;
        vector<pair<ll,ll>> dp_1(n-1), dp_2(n-1);
        dp_1[0] = dp_2[0] = {0, a[0]};
        for (int i = 1; i < n-1; i++) {
            int x = min(s, a[i]), y = a[i] - x;
            dp_1[i] = min(make_pair(dp_1[i-1].first + dp_1[i-1].second * x, y),
                          make_pair(dp_2[i-1].first + dp_2[i-1].second * x, y));
            dp_2[i] = min(make_pair(dp_1[i-1].first + dp_1[i-1].second * y, x),
                          make_pair(dp_2[i-1].first + dp_2[i-1].second * y, x));
        }
        cout << min(dp_1[n-2].first + dp_1[n-2].second * a[n-1],
                    dp_2[n-2].first + dp_2[n-2].second * a[n-1]) << '\n';
    }
    return 0;
}
