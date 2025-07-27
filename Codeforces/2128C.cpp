#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool ok(vi& b) {
    int cur_min = 1e9+7;
    for (auto x : b) {
        if (x >= 2 * cur_min)
            return false;
        cur_min = min(cur_min, x);
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi b(n);
        for (auto& x : b)
            cin >> x;
        cout << (ok(b) ? "YES" : "NO") << '\n';
    }
}
