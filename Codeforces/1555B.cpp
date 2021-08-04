#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        int res = INT_MAX;
        if (W - (x2 - x1) >= w) res = min({res, w - x1, w - (W - x2)});
        if (H - (y2 - y1) >= h) res = min({res, h - y1, h - (H - y2)});
        if (res < 0) res = 0;
        if (res == INT_MAX) res = -1;
        cout << res << '\n';
    }
    return 0;
}