#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll diff(ll x, ll y, ll z) {
    return max({x, y, z}) - min({x, y, z});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll H, W;
    cin >> H >> W;
    ll res = min(W, H);
    if (H % 3 == 0 || W % 3 == 0) res = 0;
    for (int i = 1; i < W; i++)
        res = min(res, diff(H/2*i, (H+1)/2*i, H*(W-i)));
    for (int i = 1; i < H; i++)
        res = min(res, diff(W/2*i, (W+1)/2*i, W*(H-i)));
    cout << res << '\n';
    return 0;
}