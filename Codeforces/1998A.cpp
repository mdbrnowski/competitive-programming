#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        int offset = k / 2;
        for (int i = 0; i < (k | 1); i++) {
            if ((k & 1) == 0 && i == offset)
                continue;
            cout << xc + i - offset << " " << yc << '\n';
        }
    }
    return 0;
}
