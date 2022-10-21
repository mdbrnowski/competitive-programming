#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        for (int i = 0; i < 2*m; i++) cin >> x;
        cout << (n > m ? "YES" : "NO") << '\n';
    }
    return 0;
}