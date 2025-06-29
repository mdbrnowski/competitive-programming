#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        ll d;
        cin >> d;
        if (d % 9 != 0) {
            cout << "NONE\n";
        } else {
            cout << d / 9 << ' ' << d / 9 * 10 << '\n';
        }
    }
}
