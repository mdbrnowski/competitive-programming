#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n > m) { cout << "YES\n"; return 0; }
    bitset<2001> b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= m;
        b |= (b << x);
        b |= (b >> m);
        b[x] = true;
    }
    cout << (b[0] ? "YES" : "NO") << '\n';
    return 0;
}
