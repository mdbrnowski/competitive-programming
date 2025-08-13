#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

constexpr int INF = 1e8;

vi divisors(int x) {
    vi divs;
    for (int d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            divs.push_back(d);
            if (d != x / d)
                divs.push_back(x / d);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

int count_moves(int x, int k) {
    if (x == 1)
        return 0;
    vi divs = divisors(x);
    vi dp(sz(divs), INF);
    dp[0] = 0;
    for (int i = 1; i < sz(divs); i++) {
        for (int j = 0; j < i; j++) {
            if (divs[i] % divs[j] == 0 && divs[i] / divs[j] <= k)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    return dp.back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int gcdxy = gcd(x, y);
        x /= gcdxy, y /= gcdxy;

        int res = count_moves(x, k) + count_moves(y, k);
        cout << (res >= INF ? -1 : res) << '\n';
    }
}
