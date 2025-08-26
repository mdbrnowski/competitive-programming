#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (b % 2 == n % 2 && (b >= a || a % 2 == b % 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
