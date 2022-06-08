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
        int k = (n - 3) / 3;
        cout << k + 1 + (n % 3 == 2) << ' '
             << k + 2 + (n % 3 > 0) << ' '
             << k << '\n';
    }
    return 0;
}