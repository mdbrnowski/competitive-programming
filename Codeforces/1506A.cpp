#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        x--;
        ll row = x % n;
        ll col = x / n;
        cout << row * m + col + 1 << '\n';
    }
    return 0;
}