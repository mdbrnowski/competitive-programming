#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0 0\n";
            continue;
        }
        if (a < b) swap(a, b);
        cout << a-b << ' ';
        cout << min(a % (a-b), (a-b) - a % (a-b)) << '\n';
    }
    return 0;
}