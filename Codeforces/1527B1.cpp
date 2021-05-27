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
        int z = count(s.begin(), s.end(), '0');
        if (z == 1 | (z & 1) == 0) cout << "BOB\n";
        else cout << "ALICE\n";
    }
    return 0;
}