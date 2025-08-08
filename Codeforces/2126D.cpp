#include <bits/stdc++.h>
using namespace std;

struct C {
    int l, r, real;
    bool operator<(const C& other) const {
        return l < other.l;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        multiset<C> casinos;
        for (int i = 0; i < n; i++) {
            int l, r, real;
            cin >> l >> r >> real;
            casinos.insert(C{l, r, real});
        }

        int res = k;
        for (auto x : casinos) {
            if (x.l > res)
                break;
            res = max(res, x.real);
        }

        cout << res << '\n';
    }
}
