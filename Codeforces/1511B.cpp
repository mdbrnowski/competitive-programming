#include <bits/stdc++.h>
using namespace std;

#define REP(n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << 1;
        REP(a-1) cout << 0;
        cout << ' ';
        REP(b-c+1) cout << 1;
        REP(c-1) cout << 0;
        cout << '\n';
    }
    return 0;
}