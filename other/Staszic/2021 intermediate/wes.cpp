#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        int n, d;
        cin >> n >> d;
        int res = n / __gcd(n, d);
        cout << res << '\n';
    }
    return 0;
}