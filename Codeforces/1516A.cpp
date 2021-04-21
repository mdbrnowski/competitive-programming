#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int moved = 0;
        for (int i = 0; i < n-1; i++) {
            int x;
            cin >> x;
            if (x <= k) {
                cout << 0;
                moved += x;
                k -= x;
            } else {
                cout << x - k;
                moved += k;
                k = 0;
            }
            cout << ' ';
        }
        int last;
        cin >> last;
        cout << moved + last << '\n';
    }
    return 0;
}