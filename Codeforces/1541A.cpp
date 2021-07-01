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
        if (n & 1) {
            cout << "3 1 2 ";
            for (int i = 2; i <= n/2; i++)
                cout << 2 * i + 1 << ' ' << 2 * i << ' ';
        }
        else
            for (int i = 1; i <= n/2; i++)
                cout << 2 * i << ' ' << 2 * i - 1 << ' ';
        cout << '\n';
    }
    return 0;
}