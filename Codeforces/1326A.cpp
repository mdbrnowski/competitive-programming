#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << -1;
        } else {
            cout << 2;
            for (int i = 1; i < n; i++)
                cout << 3;
        }
        cout << "\n";
    }
}
