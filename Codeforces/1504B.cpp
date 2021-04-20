#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        a.push_back('0'), b.push_back('0');
        int zeros = 0, ones = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') zeros++;
            else ones++;
            if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && zeros != ones) {
                cout << "NO\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
    }
    return 0;
}