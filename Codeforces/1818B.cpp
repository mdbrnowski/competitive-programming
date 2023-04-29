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
        if (n == 1) { cout << 1 << '\n'; continue; }
        if (n & 1) { cout << -1 << '\n'; continue; }
        for (int i = 1; i <= n/2; i++)
            cout << i * 2 << ' ' << i * 2 - 1 << ' ';
        cout << '\n';
    }
    return 0;
}
