#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ll n, d, c, m; string s;
        cin >> n >> d >> c >> m >> s;
        bool res = true;
        int i;
        for (i = 0; i < n; i++) {
            if (s[i] == 'D') d--, c += m;
            else c--;
            if (d < 0 || c < 0) {
                res = false;
                break;
            }
        }
        bool all_cats = true;
        for (; i < n; i++)
            if (s[i] == 'D') all_cats = false;
        cout << "Case #" << tc << ": " << (res || all_cats ? "YES" : "NO") << '\n';
    }
    return 0;
}