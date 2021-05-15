#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b == 1)
            cout << "NO\n";
        else
            cout << "YES\n" << (ll) a * b << ' ' << a << ' ' << (ll) a * (b + 1) << '\n';
    }
    return 0;
}