#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        cout << (s[0] != s[n - 1] ? "YES" : "NO") << '\n';
    }
    return 0;
}
