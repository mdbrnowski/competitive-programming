#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < 2*n; i++) {
            int x;
            cin >> x;
            res += (x&1);
        }
        cout << (res == n ? "Yes" : "No") << '\n';
    }
    return 0;
}