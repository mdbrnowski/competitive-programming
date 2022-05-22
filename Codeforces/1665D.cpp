#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x = 0;
        for (int m = 1; m <= 30; m++) {
            int a = (1 << (m - 1));
            cout << "? " << a - x << ' ' << 3 * a - x << '\n';
            int ans;
            cin >> ans;
            if (ans == (1 << m))
                x += a;
        }
        cout << "! " << x << '\n';
    }
    return 0;
}