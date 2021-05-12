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
        int n2 = n * n;
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        int x = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout << x << (j == n-1 ? '\n' : ' ');
                x += 2;
                if (x > n2) x = 2;
            }
    }
    return 0;
}