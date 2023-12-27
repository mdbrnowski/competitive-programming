#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (x)
                s.insert((x > 0) ? 0 : 1);
            if (y)
                s.insert((y > 0) ? 2 : 3);
        }
        cout << (sz(s) == 4 ? "NO" : "YES") << '\n';
    }
    return 0;
}
