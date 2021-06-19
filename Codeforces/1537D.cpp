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
        if (n & 1) cout << "Bob";
        else if ((1 << __lg(n)) == n && (__lg(n) & 1)) cout << "Bob";
        else cout << "Alice";
        cout << '\n';
    }
    return 0;
}