#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        int maxL = max(l, L);
        int minR = min(r, R);
        cout << max(-1, minR - maxL) + (l != L) + (r != R) << '\n';
    }
    return 0;
}
