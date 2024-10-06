#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        int res = (W - G) % MOD * ((1 + 2 * L) % MOD) % MOD;
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
